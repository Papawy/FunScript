#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "FunOpCodes.h"

namespace Fun
{
	namespace Utils
	{
		std::vector<std::string> SplitLine(std::string line);

		Fun::OpCodes::OpCodeList::iterator FindOpCode(std::string opcodeName);

		Fun::OpCodes::OpCodeList::iterator FindOpCode(std::int16_t opcodeId);

		Fun::Types::E_FUN_TYPES DeductType(std::string arg);
	}
}