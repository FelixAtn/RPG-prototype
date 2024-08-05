#pragma once
#include <vector>
#include <string>

class FileLoader
{
public:
	using Matrix = std::vector<std::vector<int>>;

	FileLoader() = default;
	~FileLoader() = default;

	static bool LoadFile(const std::string& fileLocation, Matrix& outMatrix);
};
