#pragma once
#include "CommandIface.h"

/* Concrete class representing a DELETE command */

class DeleteCommand :	public CommandIface
{
public:
	DeleteCommand();

private:
	std::string m_key;
    Result ReadArguments(const std::string& arguments)  final;
	Result DoExecute() const final;
};

