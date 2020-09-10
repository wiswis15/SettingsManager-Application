#pragma once
#include <string>
#include "CommandIface.h"
#include <memory>
#include "DeleteCommand.h"
#include "SetCommand.h"
#include "GetCommand.h"
#include "Definitions.h"

/* Factory class to create commands objects*/

class CommandFactory
{
public:
	std::shared_ptr <CommandIface> CreateCommand(CommandType type)const;
};

