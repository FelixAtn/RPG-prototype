#pragma once
#include <iostream>
class BitArithmetics
{
public:
	BitArithmetics();

	// Overwrites this bitmask
	void SetMask(BitArithmetics& other);
	
	// Returns binary representation of BitMask
	uint32_t GetMask() const;

	// Returns True if bit at a certain position == 1 
	bool GetBit(int toPosition) const;

	// Sets BIT at a specified Position to 1 or 0 (True or false)
	void SetBit(int toPosition, bool on);
	
	// Sets BIT at a certain position to 1 (true)
	void SetBit(int toPosition);

	// Sets bit at a certain position to 0 (false)
	void ClearBit(int toPosition);

	// Sets all Bits to 0 
	void ClearByte();

private:
	uint8_t bits;
};

