#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <map>
#include "definitions.h"
#include "interrupts.h"
#include "util.h"
#include "mmu.h"
#include "operations.h"

class Processor
{
public:
    Processor(Interrupts *inter, Memory *mem);
    void init_state();
    int step(bool print = false);
    void set_flags(u8 mask, bool b);
    void update_timer(int cycles);
    void process_interrupts();
    void execute(u8 instr);
    void cb_execute(u8 instr);

    u8 fetch_byte();
    u16 fetch_word();

    bool zero_flag();         // Z
    bool subtract_flag();     // N
    bool half_carry_flag();   // H
    bool carry_flag();        // C

    bool interrupt_pending();
    
    reg16 AF;
    reg16 BC;
    reg16 DE;	
    reg16 HL;
    reg16 SP;
    reg16 PC;

    u8 &A;
    u8 &F;
    u8 &B;
    u8 &C;
    u8 &D;
    u8 &E;
    u8 &H;
    u8 &L;

    Memory *memory; 
    Interrupts *interrupts;

    reg16 internal_timer;
    u8 timer_lsb;

    u8 &div_reg;
    
    bool IME_flag;
    int ei_count;
    bool cond_taken;
    int timer_count;
    bool halted;
    bool halt_bug;

    static const u8 ZERO = 1 << 7;       
    static const u8 SUBTRACT = 1 << 6;   
    static const u8 HALF_CARRY = 1 << 5; 
    static const u8 CARRY = 1 << 4;      

    static const int instr_cycles[256];
    static const int instr_cycles_cond[256];
    static const int cb_instr_cycles[256];
    static const u16 interrupt_addr[5];
    static const int div_cycles = 256;
};    

#endif
