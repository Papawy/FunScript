#include "SyntaxChecker.h"

#include "FunError.h"

SyntaxChecker::SyntaxChecker()
{

}

SyntaxChecker::~SyntaxChecker()
{
}

FunError SyntaxChecker::CheckLine(std::string line)
{
	return FunError();
}

std::vector<FunError> SyntaxChecker::CheckFile(std::string file)
{
	return std::vector<FunError>();
}
