#include "functions.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void set(bool &b) 
{ 
    b = true; 
}

void reset(bool &b) 
{ 
    b = false; 
}

// Check for carry from bit 3 to bit 4 in a + b
bool half_carry_add(u16 a, u16 b) 
{
    return (((a & 0xf) + (b & 0xf)) & 0x10) == 0x10;
}

// Check for carry from bit 4 to 3 in a - b 
bool half_carry_sub(u16 a, u16 b)
{
	return ((a - (b & 0xff)) & 0x10) == 0;
}

bool full_carry_add(u16 a, u16 b)
{
	return (((a & 0xff) + (b & 0xff)) & 0x100) == 0x100;
}

bool full_carry_sub(u16 a, u16 b)
{
	return false;
}

vector<u8> read_rom(size_t &file_size, string path)
{
	ifstream ifs(path, ios_base::in | ios_base::binary);
	ifs.seekg(0, ios_base::end);
	file_size = ifs.tellg();
	ifs.seekg(0, ios_base::beg);

	if (!ifs.good())
		cout << "Error reading file: " + path << endl;
	
	char *buff = new char[file_size];
	ifs.read(buff, file_size);
	vector<u8> data(buff, buff + file_size);

	ifs.close();
	delete buff;
	return data;
}