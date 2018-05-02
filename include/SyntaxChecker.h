#pragma once

#include <string>
#include <vector>

class FunError;

class SyntaxChecker
{
public:
	SyntaxChecker();
	~SyntaxChecker();

	static FunError CheckLine(std::string line);
	static std::vector<std::pair<unsigned int, FunError>> CheckFile(std::string file);
};