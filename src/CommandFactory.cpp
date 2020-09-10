#include "CommandFactory.h"

using namespace std;

/*! \fn shared_ptr<CommandIface> CommandFactory::CreateCommand(CommandType type) const
 *  \brief CommandFactory member function.
 *  \param type : command type
 *  \return a new command of type shared_ptr<CommandIface>
 */
shared_ptr<CommandIface> CommandFactory::CreateCommand(CommandType type) const
{

	switch (type)
	{
	case CommandType::SET:
	{
		shared_ptr <SetCommand> setCommand = std::make_shared<SetCommand>();
		return setCommand;
	}
	case CommandType::GET:
	{
		shared_ptr <GetCommand> getCommand = std::make_shared<GetCommand>();
		return getCommand;
	}
	case CommandType::DELETE:
	{
		shared_ptr <DeleteCommand> deleteCommand = std::make_shared<DeleteCommand>();
		return deleteCommand;
	}
	default:
		return nullptr;
	}


}
