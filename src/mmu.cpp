#include "mmu.h"
#include "utils.h"
#include "registers.h"
#include "register8bit.h"
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>

typedef Register8bit r8;

Memory::Memory(Cartridge *cart, Joypad *pad, bool enable_boot) : 
    cartridge(cart), 
    mem{0}, 
    joypad(pad), 
    enable_boot_rom(enable_boot), 
    enable_break_pt(false), 
    paused(false), 
    vram_updated(false) 
{
    mem.resize(0x10000, 0);
    init_registers();
}

u8 Memory::read(u16 addr) 
{
    switch(addr / 0x1000) 
    {
    // Switchable ROM Bank
    case 0x0: 
        if (addr <= 0x100 && (!(mem[0xff50] & 1) && enable_boot_rom)) { 
            return boot_rom[addr];
        } 
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0x7: 
        return cartridge->read(addr);
    // VRAM        
    case 8: 
    case 9:
        return mem[addr];
    // Switchable RAM bank
    case 0xa: 
    case 0xb:
        return cartridge->read(addr);
    // Internal RAM
    case 0xc:
    case 0xd:
        return mem[addr];
    case 0xe:
    case 0xf:
        if (mem_registers.find(addr) != mem_registers.end()) {
            return read_reg(addr);
        }
        else if (addr <= 0xfdff) { // Echo RAM
            return mem[addr - 0x2000];
        }
        else if (addr <= 0xfe9f) { // OAM
            return mem[addr];
        }
        else if (addr <= 0xfeff) { // unusable memory
            return 0xff;
        }
        else if (addr >= 0xff00) { // I/O Registers + High RAM
            return mem[addr];
        }   
    default:
        std::cout << "Read from address " << addr << std::endl;
        assert(false);
        return 0xff;
    }
}

void Memory::write(u16 addr, u8 data)
{
    if (enable_break_pt && addr == break_pt) { 
        paused = true; 
    }

    switch(addr / 0x1000) {
    // Select RAM/ROM bank                 
    case 0x0: 
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0x7: 
        cartridge->write(addr, data);
        break;
    // VRAM        
    case 8: 
    case 9:
        vram_updated = true;
        mem[addr] = data;
        break;
    // Switchable RAM bank
    case 0xa: 
    case 0xb:
        cartridge->write(addr, data);
        break;
    // Internal RAM
    case 0xc:
    case 0xd:
        mem[addr] = data;
        break;
    case 0xe:
    case 0xf:
        if (mem_registers.find(addr) != mem_registers.end()) {
            write_reg(addr, data);
        }
        else if (addr <= 0xfdff) { // Echo RAM
            mem[addr - 0x2000] = data;
        }
        else if (addr <= 0xfe9f) { // OAM
            vram_updated = true;
            mem[addr] = data;
        }
        // 0xfea0-0xfeff not usable
        else if (addr >= 0xff00 ) {
            mem[addr] = data;
        }
        break;
    default:
        std::cout << "Wrote to address " << addr << std::endl;
        assert(false);
    }
}

u8 Memory::read_reg(u16 addr) 
{
    switch(addr) 
    {
    case reg::JOYP: 
    {
        bool select_dpad = !utils::bit(mem_registers[addr].value(), 4);
        return (3 << 6) | joypad->get_state(select_dpad);
    }
    default:
        return mem_registers[addr].value();
    }
}

void Memory::write_reg(u16 addr, u8 data)
{
    switch(addr)
    {
    case reg::DIV:
        mem_registers[addr].write(0);
        break;
    default:
        mem_registers[addr].write(data);
    }
}

void Memory::request_interrupt(int interrupt_bit)
{
    u8 int_request = read(reg::IF);
    write(reg::IF, utils::set(int_request, interrupt_bit));
}

void Memory::load_boot(std::string file_path)
{
    utils::load_file(boot_rom, file_path);
}

void Memory::set_access_break_pt(u16 addr) 
{ 
    enable_break_pt = true;
    break_pt = addr; 
}

void Memory::clear_access_break_pt() { enable_break_pt = false; }

bool Memory::pause() { return paused; }

std::vector<u8>::iterator Memory::get_mem_ptr(u16 addr) { return mem.begin() + addr; }

void Memory::init_registers()
{
    u8 bit[8];
    for (int i = 0; i < 8; i++) {
        bit[i] = 1 << i;
    }

    mem_registers[reg::DIV] = Register8bit();
    mem_registers[reg::JOYP] = Register8bit(bit[7] | bit[6]);
    mem_registers[reg::STAT] = Register8bit(0, bit[2] | bit[1] | bit[0]);
}