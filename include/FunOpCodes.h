#pragma once

#include <string>
#include <functional>
#include <vector>
#include <tuple>

namespace Fun
{
	namespace OpCodes
	{
		std::vector < std::tuple<std::int16_t, std::string, std::int8_t, std::function<bool(std::vector<std::string>)>>> List = {
			// REGISTER OPERATIONS
			{0x1, "SETR", 2, [](std::vector <std::string> params) {return true; } },
			{0x2, "MOVR", 2, [](std::vector <std::string> params) {return true; } },
			// JUMPS
			{0x3, "LBL", 1, [](std::vector <std::string> params) {return true; } },
			{0x4, "JMP", 1, [](std::vector <std::string> params) {return true; } },
			// CONDITIONAL JUMPS
			{0x5, "IFSUP", 3, [](std::vector <std::string> params) {return true; } },
			{0x6, "IFSUPQ", 3, [](std::vector <std::string> params) {return true; } },
			{0x7, "IFINF", 3, [](std::vector <std::string> params) {return true; } },
			{0x8, "IFINFQ", 3, [](std::vector <std::string> params) {return true; } },
			{0x9, "IFEQ", 3, [](std::vector <std::string> params) {return true; } },
			{0xA, "IFNEQ", 3, [](std::vector <std::string> params) {return true; } },
			//{0xB, "IFNEG", 2, [](std::vector <std::string> params) {return true; } },
			// ARITHMETIC OPERATIONS
			{0xC, "ADD", 2, [](std::vector <std::string> params) {return true; } },
			{0xD, "SUB", 2, [](std::vector <std::string> params) {return true; } },
			{0xE, "MUL", 2, [](std::vector <std::string> params) {return true; } },
			{0xF, "DIV", 2, [](std::vector <std::string> params) {return true; } },
			{0x10, "MOD", 2, [](std::vector <std::string> params) {return true; } },
			// DRAWING
			{0x11, "DRW", 3, [](std::vector <std::string> params) {return true; } },
		};
	}
}