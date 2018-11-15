#ifndef MMU_H
#define MMU_H

#include <unordered_map>
#include <iterator>
#include "definitions.h"
#include "register16bit.h"
#include "joypad.h"
#include "cartridge.h"

class Memory
{
    friend class GPU;
    friend class Processor;
    
public:
    Memory(Cartridge *cart, Joypad *pad, bool enable_boot = 0);

    void write(u16 addr, u8 data);

    u8 read(u16 addr);
    
    void set_interrupt(int interrupt_bit);

    void load_boot(std::string s);

    void set_access_break_pt(u16 addr);

    void clear_access_break_pt();

    bool pause();

	

private:
    void write_reg(u16 addr, u8 data);
    u8 read_reg(u16 addr);
    void init_registers();
    
    std::vector<u8>::iterator get_mem_ptr(u16 addr);

    Joypad *joypad;
    Cartridge *cartridge;
    std::vector<u8> mem;

    bool enable_boot_rom;
    bool enable_break_pt;
    bool paused;
    bool vram_updated;
    bool reset_clock;

    u16 break_pt;

    std::unordered_map<u16, Register8bit> mem_registers;
    std::vector<u8> boot_rom;
    std::vector<bool> used_io;
};

#endif