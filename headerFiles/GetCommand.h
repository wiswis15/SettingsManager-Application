#pragma once
#include "CommandIface.h"


/* Concrete class representing a GET command */

class GetCommand :	public CommandIface
{
public:
	GetCommand();
protected:
	std::string m_key;
	Result ReadArguments(const std::string& arguments)  final;
	Result DoExecute() const final;
};

