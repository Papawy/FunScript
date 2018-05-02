#pragma once

#include <string>


enum E_ERR_TYPE
{
	UNKNOW,
	NO_ERROR,
	BAD_LABEL,
	BAD_OPCODE,
	BAD_PARAMETER,
	BAD_PARAMETER_NBR
};

class FunError
{
public:
	FunError();
	FunError(E_ERR_TYPE type);
	FunError(E_ERR_TYPE type, unsigned int paramNbr);
	~FunError();

	std::string What();

private:
	E_ERR_TYPE m_type;
	unsigned int m_paramNbr;
};