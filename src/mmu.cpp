#include "mmu.h"
#include "functions.h"
#include "registers.h"
#include <cstring>
#include <iostream>

Memory::Memory(Register16bit *clock) : clock_counter(clock),
    mem{0x31, 0xfe, 0xff, 0xaf, 0x21, 0xff, 0x9f, 0x32, 
        0xcb, 0x7c, 0x20, 0xfb, 0x21, 0x26, 0xff, 0x0e, 
        0x11, 0x3e, 0x80, 0x32, 0xe2, 0x0c, 0x3e, 0xf3, 
        0xe2, 0x32, 0x3e, 0x77, 0x77, 0x3e, 0xfc, 0xe0,
        0x47, 0x11, 0x04, 0x01, 0x21, 0x10, 0x80, 0x1a,
        0xcd, 0x95, 0x00, 0xcd, 0x96, 0x00, 0x13, 0x7b, 
        0xfe, 0x34, 0x20, 0xf3, 0x11, 0xd8, 0x00, 0x06, 
        0x08, 0x1a, 0x13, 0x22, 0x23, 0x05, 0x20, 0xf9, 
        0x3e, 0x19, 0xea, 0x10, 0x99, 0x21, 0x2f, 0x99, 
        0x0e, 0x0c, 0x3d, 0x28, 0x08, 0x32, 0x0d, 0x20, 
        0xf9, 0x2e, 0x0f, 0x18, 0xf3, 0x67, 0x3e, 0x64, 
        0x57, 0xe0, 0x42, 0x3e, 0x91, 0xe0, 0x40, 0x04, 
        0x1e, 0x02, 0x0e, 0x0c, 0xf0, 0x44, 0xfe, 0x90, 
        0x20, 0xfa, 0x0d, 0x20, 0xf7, 0x1d, 0x20, 0xf2, 
        0x0e, 0x13, 0x24, 0x7c, 0x1e, 0x83, 0xfe, 0x62, 
        0x28, 0x06, 0x1e, 0xc1, 0xfe, 0x64, 0x20, 0x06, 
        0x7b, 0xe2, 0x0c, 0x3e, 0x87, 0xe2, 0xf0, 0x42, 
        0x90, 0xe0, 0x42, 0x15, 0x20, 0xd2, 0x05, 0x20, 
        0x4f, 0x16, 0x20, 0x18, 0xcb, 0x4f, 0x06, 0x04,
        0xc5, 0xcb, 0x11, 0x17, 0xc1, 0xcb, 0x11, 0x17, 
        0x05, 0x20, 0xf5, 0x22, 0x23, 0x22, 0x23, 0xc9, 
        0xce, 0xed, 0x66, 0x66, 0xcc, 0x0d, 0x00, 0x0b, 
        0x03, 0x73, 0x00, 0x83, 0x00, 0x0c, 0x00, 0x0d, 
        0x00, 0x08, 0x11, 0x1f, 0x88, 0x89, 0x00, 0x0e, 
        0xdc, 0xcc, 0x6e, 0xe6, 0xdd, 0xdd, 0xd9, 0x99, 
        0xbb, 0xbb, 0x67, 0x63, 0x6e, 0x0e, 0xec, 0xcc, 
        0xdd, 0xdc, 0x99, 0x9f, 0xbb, 0xb9, 0x33, 0x3e, 
        0x3c, 0x42, 0xb9, 0xa5, 0xb9, 0xa5, 0x42, 0x3c, 
        0x21, 0x04, 0x01, 0x11, 0xa8, 0x00, 0x1a, 0x13, 
        0xbe, 0x20, 0xfe, 0x23, 0x7d, 0xfe, 0x34, 0x20, 
        0xf5, 0x06, 0x19, 0x78, 0x86, 0x23, 0x05, 0x20, 
        0xfb, 0x86, 0x20, 0xfe, 0x3e, 0x01, 0xe0, 0x50} {}

void Memory::write(u16 addr, u8 data)
{
    if (addr >= 0xfea0 && addr <= 0xfeff) { // unusable memory
        return;
    }
    /*else if (addr == reg::DIV) {
        // writing any value to DIV writes 0 and resets system counter
        mem[addr] = 0;
        clock_counter->set(0);
    }*/
    else {
        mem[addr] = data;
    }
    
}

u8 Memory::read(u16 addr) const
{
    if (addr >= 0xfea0 && addr <= 0xfeff) { // unusable memory
        return 0xff;
    }
    else if (addr == reg::IF) {

    }
    return mem[addr];
}

void Memory::set_flags(u16 addr, u8 mask, bool b)
{
    if (b) {
        mem[addr] |= mask;
    } else {
        mem[addr] &= ~mask;
    }
}

void Memory::load_cart(const char *file_path, size_t offset)
{
    utils::load_rom(mem, offset, file_path);
}

void Memory::load_cart(const char *file_path, size_t start, size_t offset)
{
    utils::load_rom(mem, start, offset, file_path);
}

void Memory::load(u8 data[], size_t offset, size_t size)
{
    memcpy(mem + offset, data, size);
}
