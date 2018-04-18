#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "FunOpCodes.h"

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

			for (int i = 0; i < line.length(); i++)
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

		auto FindOpCode(std::string opcodeName)
		{
			auto searchFunc =
				[opcodeName](std::tuple<std::int16_t, std::string, std::int8_t, std::function<bool(std::vector<std::string>)>> tuple) {
				return std::get<1>(tuple) == opcodeName;
			};

			auto it = std::find_if(Fun::OpCodes::List.begin(), Fun::OpCodes::List.end(), searchFunc);

			return it;
		}

		auto FindOpCode(std::int16_t opcodeId)
		{
			auto searchFunc =
				[opcodeId](std::tuple<std::int16_t, std::string, std::int8_t, std::function<bool(std::vector<std::string>)>> tuple) {
				return std::get<0>(tuple) == opcodeId;
			};

			auto it = std::find_if(Fun::OpCodes::List.begin(), Fun::OpCodes::List.end(), searchFunc);

			return it;
		}
	}
}