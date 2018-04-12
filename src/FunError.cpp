#include "FunError.h"

FunError::FunError()
{
	this->m_type = E_ERR_TYPE::UNKNOW;
}

FunError::FunError(E_ERR_TYPE type)
{
	this->m_type = type;
}

FunError::~FunError()
{

}

std::string FunError::What()
{
	switch (m_type)
	{
	default:
		return "Unknow Error";
		break;
	}
}