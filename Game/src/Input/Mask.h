#pragma once
#include <iostream>

class BitMask
{
public:
	BitMask();
	// Overwrite the mask
	void SetMask(BitMask& other);
	uint8_t GetMask() const;
	bool HasBit(int toPosition) const;
	void UpdateBit(int toPosition, bool on);
	void InsertBit(int toPosition);
	void ClearBit(int toPosition);
	void ClearByte();

private:
	uint8_t bits;
};
