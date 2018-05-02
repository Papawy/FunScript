#include "FunError.h"

FunError::FunError()
{
	this->m_type = E_ERR_TYPE::UNKNOW;
}

FunError::FunError(E_ERR_TYPE type)
{
	this->m_type = type;
}

FunError::FunError(E_ERR_TYPE type, unsigned int paramNbr)
{
	this->m_type = type;
	this->m_paramNbr = paramNbr;
}

FunError::~FunError()
{

}

std::string FunError::What()
{
	switch (m_type)
	{
	case E_ERR_TYPE::BAD_LABEL:
		return "Bad label (not corresponding to anything)";
		break;

	case E_ERR_TYPE::BAD_OPCODE:
		return "Bad opcode";
		break;

	case E_ERR_TYPE::BAD_PARAMETER:
		return "Bad parameter (param. " + std::to_string(this->m_paramNbr) + ")";
		break;

	case E_ERR_TYPE::BAD_PARAMETER_NBR:
		return "Bad parameter number";
		break;

	case E_ERR_TYPE::NO_ERROR:
		return "No error";
		break;

	case E_ERR_TYPE::UNKNOW:
		return "Unknow error";
		break;

	default:
		return "Unknow Error";
		break;
	}
}