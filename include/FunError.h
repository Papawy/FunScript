#pragma once

#include <string>


enum E_ERR_TYPE
{
	UNKNOW,
	NO_ERROR,
	BAD_LABEL,
	BAD_OPCODE,
	BAD_PARAMETERS,
};

class FunError
{
public:
	FunError();
	FunError(E_ERR_TYPE type);
	~FunError();

	std::string What();

private:
	E_ERR_TYPE m_type;
};