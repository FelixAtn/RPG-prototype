#include "Mask.h"

BitMask::BitMask() : bits(0)
{
}

void BitMask::SetMask(BitMask& other)
{
	bits = other.GetMask();
}

uint8_t BitMask::GetMask() const
{
	return bits;
}

bool BitMask::HasBit(int toPosition) const
{
	// Example: && [0101]  - 1 << [toPosition]2 = 0100
	return (bits & (1 << toPosition)) != 0;
}

void BitMask::UpdateBit(int toPosition, bool on)
{
	if (on)
	{
		InsertBit(toPosition);
	}
	else
	{
		ClearBit(toPosition);
	}
}

void BitMask::InsertBit(int toPosition)
{
	// Example: || 0101 - 1 << 2 [toPosition]  = 0111 
	bits = bits | 1 << toPosition;
}

void BitMask::ClearBit(int toPosition)
{
	// Example invertor: ~ 0101 - 1 << 0 [toPosition] = 0100 
	bits = bits & ~(1 << toPosition);
}

void BitMask::ClearByte()
{
	bits = 0;
}
