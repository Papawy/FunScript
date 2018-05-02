#include "Utils.h"

namespace Fun
{
	namespace Utils
	{
		std::vector<std::string> SplitLine(std::string line)
		{
			if (line.length() == 0)
				return std::vector<std::string>();

			std::vector<std::string> tokens = std::vector<std::string>();
			bool inQuotes = false;
			std::string buffer = "";

			for (size_t i = 0; i < line.length(); i++)
			{
				if (line[i] == ';')
				{
					if (!buffer.empty())
						tokens.push_back(buffer);
					break;
				}

				if (line[i] == '"')
				{
					if (inQuotes)
					{
						tokens.push_back(buffer);
						buffer = "";
						inQuotes = false;
						continue;
					}
					inQuotes = true;
					continue;
				}

				if (inQuotes == false && line[i] == ' ')
				{
					if (!buffer.empty())
					{
						tokens.push_back(buffer);
						buffer = "";
					}
					continue;
				}

				buffer += line[i];
			}

			return tokens;
		}

		Fun::OpCodes::OpCodeList::iterator FindOpCode(std::string opcodeName)
		{
			auto searchFunc =
				[opcodeName](std::tuple<std::int16_t, std::string, std::int8_t, std::vector<std::uint32_t>> tuple) {
				return std::get<1>(tuple) == opcodeName;
			};

			auto it = std::find_if(Fun::OpCodes::List.begin(), Fun::OpCodes::List.end(), searchFunc);

			return it;
		}

		Fun::OpCodes::OpCodeList::iterator FindOpCode(std::int16_t opcodeId)
		{
			auto searchFunc =
				[opcodeId](std::tuple<std::int16_t, std::string, std::int8_t, std::vector<std::uint32_t>> tuple) {
				return std::get<0>(tuple) == opcodeId;
			};

			auto it = std::find_if(Fun::OpCodes::List.begin(), Fun::OpCodes::List.end(), searchFunc);

			return it;
		}

		bool IsNumber(std::string str)
		{
			bool point = false;

			for (size_t i = 0; i < str.length(); i++)
			{
				if (str[i] == '.')
				{
					if (point == true)
						return false;
					point = true;
				}
				if (str[i] <= '0' || str[i] >= '9')
					return false;
			}
			return true;
		}

		bool StrContainGoodChar(std::string str)
		{
			for (size_t i = 0; i < str.length(); i++)
			{
				if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
					continue;
				else
					return false;
			}
			return true;
		}

		Fun::Types::E_FUN_TYPES DeductType(std::string arg)
		{
			if (arg.length() == 1 && (arg[0] >= 'A' && arg[0] <= 'H'))
				return Fun::Types::E_FUN_TYPES::REG;
			
			if (IsNumber(arg))
				return Fun::Types::E_FUN_TYPES::NBR;

			if (StrContainGoodChar(arg))
				return Fun::Types::E_FUN_TYPES::LBL;

			return Fun::Types::E_FUN_TYPES::STR;
		}
	}
}

