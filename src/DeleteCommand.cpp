#include "DeleteCommand.h"
#include <vector>


using namespace std;


/*! 
 *  Constructor of DeleteCommand
 */
DeleteCommand::DeleteCommand()
{
	m_type = CommandType::DELETE;
}


/*! \fn DeleteCommand::ReadArguments
 *  \brief check and get the commands arguments.
 *  \param arguments : command arguments
 *  \return the result of the command, result will indicate failure if arguments are not correct.
 */
Result DeleteCommand::ReadArguments(const string& arguments) 
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
		result.result = "Error: number of argument is not correct \n";
		result.result += proposeHelpMessage;
		return result;
	}

	m_key = words.front();

	result.status = true;
	return result;
}


/*! \fn DeleteCommand::DoExecute
 *  \brief Execute the command
 *  \return the result of the command.
 */
Result DeleteCommand::DoExecute() const
{
	if (!databaseManager)
	{
		Result failed;
		failed.status = false;
		failed.result = "ERROR: DeleteCommand::DoExecute() databaseManager is not set!! , DELETE command ignored!\n";
		return failed;
	}
	return databaseManager->DeleteSetting(m_key);
	
}
