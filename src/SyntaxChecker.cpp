#include "SyntaxChecker.h"

#include "FunError.h"
#include "Utils.h"

#include <sstream>
#include <iterator>
#include <tuple>
#include <locale>

SyntaxChecker::SyntaxChecker()
{

}

SyntaxChecker::~SyntaxChecker()
{
}

FunError SyntaxChecker::CheckLine(std::string line)
{
	if (line.length() == 0 || line[0] == ';')
		return FunError(E_ERR_TYPE::NO_ERROR);

	auto results = Fun::Utils::SplitLine(line);

	if (results.size() == 0)
		return FunError(E_ERR_TYPE::NO_ERROR);

	auto opcode = Fun::Utils::FindOpCode(results[0]);

	if (opcode == Fun::OpCodes::List.end())
		return FunError(E_ERR_TYPE::BAD_OPCODE);

	if (results.size() - 1 != std::get<2>(*opcode))
		return FunError(E_ERR_TYPE::BAD_PARAMETER_NBR);

	for (int i = 1; i < results.size(); i++)
	{
		if (!(std::get<3>(*opcode)[i - 1] & Fun::Utils::DeductType(results[i])))
			return FunError(E_ERR_TYPE::BAD_PARAMETER, i);
	}

	return FunError(E_ERR_TYPE::NO_ERROR);
}

std::vector<std::pair<unsigned int, FunError>> SyntaxChecker::CheckFile(std::string file)
{
	return std::vector<std::pair<unsigned int, FunError>>();
}
