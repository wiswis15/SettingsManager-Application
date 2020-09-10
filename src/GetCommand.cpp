#include "GetCommand.h"
#include <vector>


using namespace std;

GetCommand::GetCommand()
{
	m_type = CommandType::GET;
}

/*! \fn GetCommand::ReadArguments
 *  \brief check and get the commands arguments.
 *  \param arguments : command arguments
 *  \return the result of the command, result will indicate failure if arguments are not correct.
 */
Result GetCommand::ReadArguments(const string& arguments)
{

	size_t pos = 0;
	size_t nextpos = 0;
	vector<string> words;
	do
	{
		nextpos = arguments.find_first_of(" ", pos);
		words.push_back(arguments.substr(pos, nextpos));
		pos = nextpos + 1;
	} while (nextpos != std::string::npos);

	Result result;
	if (words.size() != 1)
	{
		result.status = false;
		result.result += "Error: number of argument is not correct \n";
		result.result += "Type help to get the available commands. \n";
		return result;
	}

	m_key = words.front();

	return result;
}

/*! \fn GetCommand::DoExecute
 *  \brief Execute the command
 *  \return the result of the command.
 */
Result GetCommand::DoExecute() const
{
	if (!databaseManager)
	{
		Result failed;
		failed.status = false;
		failed.result = "ERROR: GetCommand::DoExecute() databaseManager is not set!! , GET command ignored!\n";
		return failed;
	}
	return databaseManager->GetSetting(m_key);
}
