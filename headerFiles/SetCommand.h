#pragma once
#include "CommandIface.h"
#include <string>

/* Concrete class representing a SET command */

class SetCommand : 	public CommandIface
{
public:
	SetCommand();

protected:
	Result ReadArguments(const std::string& arguments)  final;
	Result DoExecute() const final;
	std::pair<std::string, std::string> m_command;


};

