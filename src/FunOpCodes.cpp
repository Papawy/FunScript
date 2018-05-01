#include "FunOpCodes.h"

namespace Fun
{
	namespace OpCodes
	{
		OpCodeList List = {
			// REGISTER OPERATIONS
			{ 0x1, "SETR", 2,{ Types::REG, Types::REG | Types::NBR | Types::STR } },
			{ 0x2, "MOVR", 2,{ Types::REG | Types::NBR | Types::STR, Types::REG } },
			// JUMPS
			{ 0x3, "LBL", 1,{ Types::LBL } },
			{ 0x4, "JMP", 1,{ Types::LBL } },
			// CONDITIONAL JUMPS
			{ 0x5, "IFSUP", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			{ 0x6, "IFSUPQ", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			{ 0x7, "IFINF", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			{ 0x8, "IFINFQ", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			{ 0x9, "IFEQ", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			{ 0xA, "IFNEQ", 3,{ Types::REG, Types::REG | Types::NBR, Types::LBL } },
			//{0xB, "IFNEG", 2, { Types::REG, Types::LBL } },
			// ARITHMETIC OPERATIONS
			{ 0xC, "ADD", 2,{ Types::REG, Types::REG | Types::NBR } },
			{ 0xD, "SUB", 2,{ Types::REG, Types::REG | Types::NBR } },
			{ 0xE, "MUL", 2,{ Types::REG, Types::REG | Types::NBR } },
			{ 0xF, "DIV", 2,{ Types::REG, Types::REG | Types::NBR } },
			{ 0x10, "MOD", 2,{ Types::REG, Types::REG | Types::NBR } },
			// DRAWING
			{ 0x11, "DRW", 3,{ Types::REG | Types::NBR, Types::REG | Types::NBR, Types::REG | Types::NBR } },
		};
	}
}