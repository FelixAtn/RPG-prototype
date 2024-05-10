#include "BitArithmetics.h"

BitArithmetics::BitArithmetics() : bits(0) {}

void BitArithmetics::SetMask(BitArithmetics& other)
{
	bits = other.GetMask();
}
uint32_t BitArithmetics::GetMask() const
{
	return bits;
}
bool BitArithmetics::GetBit(int toPosition) const
{
	// Example: && [0101]  - 1 << [toPosition]2 = 0100
	return (bits & (1 << toPosition)) != 0;
}
void BitArithmetics::SetBit(int toPosition, bool on)
{
	if (on)
	{
		SetBit(toPosition);
	}
	else
	{
		ClearBit(toPosition);
	}
}
void BitArithmetics::SetBit(int toPosition)
{
	// Example: || 0101 - 1 << 2 [toPosition]  = 0111 
	bits = bits | 1 << toPosition;
}
void BitArithmetics::ClearBit(int toPosition)
{
	// Example invertor: ~ 0101 - 1 << 0 [toPosition] = 0100 
	bits = bits & ~(1 << toPosition);
}
void BitArithmetics::ClearByte()
{
	bits = 0;
}
