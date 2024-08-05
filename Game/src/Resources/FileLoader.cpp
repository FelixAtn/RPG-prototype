#include "FileLoader.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

bool FileLoader::LoadFile(const std::string& fileLocation, Matrix& outMatrix)
{
	std::ifstream file(fileLocation);
	if (!file.is_open())
	{
		return false;
	}

	std::string line;
	if (std::getline(file, line); !line.contains("[MapData]:"))
	{
		return false;
	}

	while (std::getline(file, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), [&](char chr) { return std::isspace(chr); }), line.end());
		if (line.empty())
		{
			continue;
		}

		if (line[0] == ';')
		{
			continue;
		}

		std::vector<int> rowData;
		std::stringstream ss(line);
		std::string value;

		while (std::getline(ss, value, ','))
		{
			rowData.push_back(std::stoi(value));
		}

		outMatrix.push_back(rowData);
	}

	return !outMatrix.empty();
}
