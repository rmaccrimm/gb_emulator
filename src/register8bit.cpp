#include "register8bit.h"

Register8bit::Register8bit(): byte(0) {}

u8 Register8bit::value() { return byte; }

void Register8bit::set(u8 x) { byte = x; }

void Register8bit::increment() { byte++; }

void Register8bit::decrement() { byte--; }

void Register8bit::add(u8 x) { byte += x; }
