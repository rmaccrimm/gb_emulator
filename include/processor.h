#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <map>
#include "definitions.h"
#include "register8bit.h"
#include "register16bit.h"

class Processor
{
	typedef void (Processor::*opfunc)(void);
	typedef std::map<u8, opfunc> OpcodeMap;

	struct Flag
	{
		bool zero;
		bool subtract;
		bool half_carry;
		bool carry;
	};
	
public:
	Processor();
	void execute(u8 instr);
	void map_to_memory(u8 program[], size_t nbytes, size_t start);
	
private:
	Register8bit A;
	Register8bit F;
	Register8bit B;
	Register8bit C;
	Register8bit D;
	Register8bit E;
	Register8bit H;
	Register8bit L;
	
	Register16bit AF;
	Register16bit BC;
	Register16bit DE;	
	Register16bit HL;
	Register16bit SP;
	Register16bit PC;

	Flag flag;
	u8 memory[0x10000]; // 16 kB memory

	OpcodeMap opcodes;
	OpcodeMap cb_opcodes;

	void opcode0x00();
	void opcode0x01();
	void opcode0x02();
	void opcode0x03();
	void opcode0x04();
	void opcode0x05();
	void opcode0x06();
	void opcode0x07();
	void opcode0x08();
	void opcode0x09();
	void opcode0x0a();
	void opcode0x0b();
	void opcode0x0c();
	void opcode0x0d();
	void opcode0x0e();
	void opcode0x0f();
	void opcode0x10();
	void opcode0x11();
	void opcode0x12();
	void opcode0x13();
	void opcode0x14();
	void opcode0x15();
	void opcode0x16();
	void opcode0x17();
	void opcode0x18();
	void opcode0x19();
	void opcode0x1a();
	void opcode0x1b();
	void opcode0x1c();
	void opcode0x1d();
	void opcode0x1e();
	void opcode0x1f();
	void opcode0x20();
	void opcode0x21();
	void opcode0x22();
	void opcode0x23();
	void opcode0x24();
	void opcode0x25();
	void opcode0x26();
	void opcode0x27();
	void opcode0x28();
	void opcode0x29();
	void opcode0x2a();
	void opcode0x2b();
	void opcode0x2c();
	void opcode0x2d();
	void opcode0x2e();
	void opcode0x2f();
	void opcode0x30();
	void opcode0x31();
	void opcode0x32();
	void opcode0x33();
	void opcode0x34();
	void opcode0x35();
	void opcode0x36();
	void opcode0x37();
	void opcode0x38();
	void opcode0x39();
	void opcode0x3a();
	void opcode0x3b();
	void opcode0x3c();
	void opcode0x3d();
	void opcode0x3e();
	void opcode0x3f();
	void opcode0x40();
	void opcode0x41();
	void opcode0x42();
	void opcode0x43();
	void opcode0x44();
	void opcode0x45();
	void opcode0x46();
	void opcode0x47();
	void opcode0x48();
	void opcode0x49();
	void opcode0x4a();
	void opcode0x4b();
	void opcode0x4c();
	void opcode0x4d();
	void opcode0x4e();
	void opcode0x4f();
	void opcode0x50();
	void opcode0x51();
	void opcode0x52();
	void opcode0x53();
	void opcode0x54();
	void opcode0x55();
	void opcode0x56();
	void opcode0x57();
	void opcode0x58();
	void opcode0x59();
	void opcode0x5a();
	void opcode0x5b();
	void opcode0x5c();
	void opcode0x5d();
	void opcode0x5e();
	void opcode0x5f();
	void opcode0x60();
	void opcode0x61();
	void opcode0x62();
	void opcode0x63();
	void opcode0x64();
	void opcode0x65();
	void opcode0x66();
	void opcode0x67();
	void opcode0x68();
	void opcode0x69();
	void opcode0x6a();
	void opcode0x6b();
	void opcode0x6c();
	void opcode0x6d();
	void opcode0x6e();
	void opcode0x6f();
	void opcode0x70();
	void opcode0x71();
	void opcode0x72();
	void opcode0x73();
	void opcode0x74();
	void opcode0x75();
	void opcode0x76();
	void opcode0x77();
	void opcode0x78();
	void opcode0x79();
	void opcode0x7a();
	void opcode0x7b();
	void opcode0x7c();
	void opcode0x7d();
	void opcode0x7e();
	void opcode0x7f();
	void opcode0x80();
	void opcode0x81();
	void opcode0x82();
	void opcode0x83();
	void opcode0x84();
	void opcode0x85();
	void opcode0x86();
	void opcode0x87();
	void opcode0x88();
	void opcode0x89();
	void opcode0x8a();
	void opcode0x8b();
	void opcode0x8c();
	void opcode0x8d();
	void opcode0x8e();
	void opcode0x8f();
	void opcode0x90();
	void opcode0x91();
	void opcode0x92();
	void opcode0x93();
	void opcode0x94();
	void opcode0x95();
	void opcode0x96();
	void opcode0x97();
	void opcode0x98();
	void opcode0x99();
	void opcode0x9a();
	void opcode0x9b();
	void opcode0x9c();
	void opcode0x9d();
	void opcode0x9e();
	void opcode0x9f();
	void opcode0xa0();
	void opcode0xa1();
	void opcode0xa2();
	void opcode0xa3();
	void opcode0xa4();
	void opcode0xa5();
	void opcode0xa6();
	void opcode0xa7();
	void opcode0xa8();
	void opcode0xa9();
	void opcode0xaa();
	void opcode0xab();
	void opcode0xac();
	void opcode0xad();
	void opcode0xae();
	void opcode0xaf();
	void opcode0xb0();
	void opcode0xb1();
	void opcode0xb2();
	void opcode0xb3();
	void opcode0xb4();
	void opcode0xb5();
	void opcode0xb6();
	void opcode0xb7();
	void opcode0xb8();
	void opcode0xb9();
	void opcode0xba();
	void opcode0xbb();
	void opcode0xbc();
	void opcode0xbd();
	void opcode0xbe();
	void opcode0xbf();
	void opcode0xc0();
	void opcode0xc1();
	void opcode0xc2();
	void opcode0xc3();
	void opcode0xc4();
	void opcode0xc5();
	void opcode0xc6();
	void opcode0xc7();
	void opcode0xc8();
	void opcode0xc9();
	void opcode0xca();
	void opcode0xcb();
	void opcode0xcc();
	void opcode0xcd();
	void opcode0xce();
	void opcode0xcf();
	void opcode0xd0();
	void opcode0xd1();
	void opcode0xd2();
	void opcode0xd4();
	void opcode0xd5();
	void opcode0xd6();
	void opcode0xd7();
	void opcode0xd8();
	void opcode0xd9();
	void opcode0xda();
	void opcode0xdb();
	void opcode0xdc();
	void opcode0xde();
	void opcode0xdf();
	void opcode0xe0();
	void opcode0xe1();
	void opcode0xe2();
	void opcode0xe5();
	void opcode0xe6();
	void opcode0xe7();
	void opcode0xe8();
	void opcode0xe9();
	void opcode0xea();
	void opcode0xeb();
	void opcode0xee();
	void opcode0xef();
	void opcode0xf0();
	void opcode0xf1();
	void opcode0xf2();
	void opcode0xf3();
	void opcode0xf5();
	void opcode0xf6();
	void opcode0xf7();
	void opcode0xf8();
	void opcode0xf9();
	void opcode0xfa();
	void opcode0xfb();
	void opcode0xfe();
	void opcode0xff();
	void opcode_cb0x00();
	void opcode_cb0x01();
	void opcode_cb0x02();
	void opcode_cb0x03();
	void opcode_cb0x04();
	void opcode_cb0x05();
	void opcode_cb0x06();
	void opcode_cb0x07();
	void opcode_cb0x08();
	void opcode_cb0x09();
	void opcode_cb0x0a();
	void opcode_cb0x0b();
	void opcode_cb0x0c();
	void opcode_cb0x0d();
	void opcode_cb0x0e();
	void opcode_cb0x0f();
	void opcode_cb0x10();
	void opcode_cb0x11();
	void opcode_cb0x12();
	void opcode_cb0x13();
	void opcode_cb0x14();
	void opcode_cb0x15();
	void opcode_cb0x16();
	void opcode_cb0x17();
	void opcode_cb0x18();
	void opcode_cb0x19();
	void opcode_cb0x1a();
	void opcode_cb0x1b();
	void opcode_cb0x1c();
	void opcode_cb0x1d();
	void opcode_cb0x1e();
	void opcode_cb0x1f();
	void opcode_cb0x20();
	void opcode_cb0x21();
	void opcode_cb0x22();
	void opcode_cb0x23();
	void opcode_cb0x24();
	void opcode_cb0x25();
	void opcode_cb0x26();
	void opcode_cb0x27();
	void opcode_cb0x28();
	void opcode_cb0x29();
	void opcode_cb0x2a();
	void opcode_cb0x2b();
	void opcode_cb0x2c();
	void opcode_cb0x2d();
	void opcode_cb0x2e();
	void opcode_cb0x2f();
	void opcode_cb0x30();
	void opcode_cb0x31();
	void opcode_cb0x32();
	void opcode_cb0x33();
	void opcode_cb0x34();
	void opcode_cb0x35();
	void opcode_cb0x36();
	void opcode_cb0x37();
	void opcode_cb0x38();
	void opcode_cb0x39();
	void opcode_cb0x3a();
	void opcode_cb0x3b();
	void opcode_cb0x3c();
	void opcode_cb0x3d();
	void opcode_cb0x3e();
	void opcode_cb0x3f();
	void opcode_cb0x40();
	void opcode_cb0x41();
	void opcode_cb0x42();
	void opcode_cb0x43();
	void opcode_cb0x44();
	void opcode_cb0x45();
	void opcode_cb0x46();
	void opcode_cb0x47();
	void opcode_cb0x48();
	void opcode_cb0x49();
	void opcode_cb0x4a();
	void opcode_cb0x4b();
	void opcode_cb0x4c();
	void opcode_cb0x4d();
	void opcode_cb0x4e();
	void opcode_cb0x4f();
	void opcode_cb0x50();
	void opcode_cb0x51();
	void opcode_cb0x52();
	void opcode_cb0x53();
	void opcode_cb0x54();
	void opcode_cb0x55();
	void opcode_cb0x56();
	void opcode_cb0x57();
	void opcode_cb0x58();
	void opcode_cb0x59();
	void opcode_cb0x5a();
	void opcode_cb0x5b();
	void opcode_cb0x5c();
	void opcode_cb0x5d();
	void opcode_cb0x5e();
	void opcode_cb0x5f();
	void opcode_cb0x60();
	void opcode_cb0x61();
	void opcode_cb0x62();
	void opcode_cb0x63();
	void opcode_cb0x64();
	void opcode_cb0x65();
	void opcode_cb0x66();
	void opcode_cb0x67();
	void opcode_cb0x68();
	void opcode_cb0x69();
	void opcode_cb0x6a();
	void opcode_cb0x6b();
	void opcode_cb0x6c();
	void opcode_cb0x6d();
	void opcode_cb0x6e();
	void opcode_cb0x6f();
	void opcode_cb0x70();
	void opcode_cb0x71();
	void opcode_cb0x72();
	void opcode_cb0x73();
	void opcode_cb0x74();
	void opcode_cb0x75();
	void opcode_cb0x76();
	void opcode_cb0x77();
	void opcode_cb0x78();
	void opcode_cb0x79();
	void opcode_cb0x7a();
	void opcode_cb0x7b();
	void opcode_cb0x7c();
	void opcode_cb0x7d();
	void opcode_cb0x7e();
	void opcode_cb0x7f();
	void opcode_cb0x80();
	void opcode_cb0x81();
	void opcode_cb0x82();
	void opcode_cb0x83();
	void opcode_cb0x84();
	void opcode_cb0x85();
	void opcode_cb0x86();
	void opcode_cb0x87();
	void opcode_cb0x88();
	void opcode_cb0x89();
	void opcode_cb0x8a();
	void opcode_cb0x8b();
	void opcode_cb0x8c();
	void opcode_cb0x8d();
	void opcode_cb0x8e();
	void opcode_cb0x8f();
	void opcode_cb0x90();
	void opcode_cb0x91();
	void opcode_cb0x92();
	void opcode_cb0x93();
	void opcode_cb0x94();
	void opcode_cb0x95();
	void opcode_cb0x96();
	void opcode_cb0x97();
	void opcode_cb0x98();
	void opcode_cb0x99();
	void opcode_cb0x9a();
	void opcode_cb0x9b();
	void opcode_cb0x9c();
	void opcode_cb0x9d();
	void opcode_cb0x9e();
	void opcode_cb0x9f();
	void opcode_cb0xa0();
	void opcode_cb0xa1();
	void opcode_cb0xa2();
	void opcode_cb0xa3();
	void opcode_cb0xa4();
	void opcode_cb0xa5();
	void opcode_cb0xa6();
	void opcode_cb0xa7();
	void opcode_cb0xa8();
	void opcode_cb0xa9();
	void opcode_cb0xaa();
	void opcode_cb0xab();
	void opcode_cb0xac();
	void opcode_cb0xad();
	void opcode_cb0xae();
	void opcode_cb0xaf();
	void opcode_cb0xb0();
	void opcode_cb0xb1();
	void opcode_cb0xb2();
	void opcode_cb0xb3();
	void opcode_cb0xb4();
	void opcode_cb0xb5();
	void opcode_cb0xb6();
	void opcode_cb0xb7();
	void opcode_cb0xb8();
	void opcode_cb0xb9();
	void opcode_cb0xba();
	void opcode_cb0xbb();
	void opcode_cb0xbc();
	void opcode_cb0xbd();
	void opcode_cb0xbe();
	void opcode_cb0xbf();
	void opcode_cb0xc0();
	void opcode_cb0xc1();
	void opcode_cb0xc2();
	void opcode_cb0xc3();
	void opcode_cb0xc4();
	void opcode_cb0xc5();
	void opcode_cb0xc6();
	void opcode_cb0xc7();
	void opcode_cb0xc8();
	void opcode_cb0xc9();
	void opcode_cb0xca();
	void opcode_cb0xcb();
	void opcode_cb0xcc();
	void opcode_cb0xcd();
	void opcode_cb0xce();
	void opcode_cb0xcf();
	void opcode_cb0xd0();
	void opcode_cb0xd1();
	void opcode_cb0xd2();
	void opcode_cb0xd3();
	void opcode_cb0xd4();
	void opcode_cb0xd5();
	void opcode_cb0xd6();
	void opcode_cb0xd7();
	void opcode_cb0xd8();
	void opcode_cb0xd9();
	void opcode_cb0xda();
	void opcode_cb0xdb();
	void opcode_cb0xdc();
	void opcode_cb0xdd();
	void opcode_cb0xde();
	void opcode_cb0xdf();
	void opcode_cb0xe0();
	void opcode_cb0xe1();
	void opcode_cb0xe2();
	void opcode_cb0xe3();
	void opcode_cb0xe4();
	void opcode_cb0xe5();
	void opcode_cb0xe6();
	void opcode_cb0xe7();
	void opcode_cb0xe8();
	void opcode_cb0xe9();
	void opcode_cb0xea();
	void opcode_cb0xeb();
	void opcode_cb0xec();
	void opcode_cb0xed();
	void opcode_cb0xee();
	void opcode_cb0xef();
	void opcode_cb0xf0();
	void opcode_cb0xf1();
	void opcode_cb0xf2();
	void opcode_cb0xf3();
	void opcode_cb0xf4();
	void opcode_cb0xf5();
	void opcode_cb0xf6();
	void opcode_cb0xf7();
	void opcode_cb0xf8();
	void opcode_cb0xf9();
	void opcode_cb0xfa();
	void opcode_cb0xfb();
	void opcode_cb0xfc();
	void opcode_cb0xfd();
	void opcode_cb0xfe();
	void opcode_cb0xff();
};

#endif
