#pragma once

#include <string>
#include <functional>
#include <vector>
#include <tuple>

namespace Fun
{
	namespace Types
	{
		typedef enum E_FUN_TYPES
		{
			BAD = 0b0000000000000000,
			REG = 0b0000000000000001,
			LBL = 0b0000000000000010,
			NBR = 0b0000000000000100,
			STR = 0b0000000000001000
		} E_FUN_TYPES;
	}

	namespace OpCodes
	{
		typedef std::vector < std::tuple<std::int16_t, std::string, std::int8_t, std::vector<std::uint32_t>>> OpCodeList;

		extern OpCodeList List;
	}
}