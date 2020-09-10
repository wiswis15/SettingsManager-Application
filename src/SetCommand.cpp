#include "SetCommand.h"
#include <vector>
#include <sstream> 


using namespace std;

SetCommand::SetCommand()
{
	m_type = CommandType::SET;
}

/*! \fn SetCommand::ReadArguments
 *  \brief check and get the commands arguments.
 *  \param arguments : command arguments
 *  \return the result of the command, result will indicate failure if arguments are not correct.
 */
Result SetCommand::ReadArguments(const string& arguments)
{

	size_t pos = 0;
	size_t nextpos = 0;
	vector<string> words;
	do
	{
		nextpos = arguments.find_first_of(" ", pos);
		words.push_back(arguments.substr(pos, nextpos));
		pos = nextpos+1;
	} while (nextpos != std::string::npos);


	Result result;

	//Set command must have only two arguments
	if (words.size() != 2)
	{
		result.status = false;
		result.result = "Error: number of argument is not correct \n";
		result.result += proposeHelpMessage;
		return result;
	}

	// Check the number of characters
	if (words.at(0).size() > max_CharKeys || words.at(1).size() > max_CharKeysValue)
	{
		result.status = false;
		std::stringstream  errorMesage;
		errorMesage << "Error: Two long key or value!\n" << "Max Key characters= " << max_CharKeys//
			<< " and max value characters= " << max_CharKeysValue << "\n";
		result.result+=errorMesage.str();
		return result;
	}
	m_command = make_pair(words.at(0), words.at(1));
	result.status = true;
	return result;

}

/*! \fn SetCommand::DoExecute
 *  \brief Execute the command
 *  \return the result of the command.
 */
Result SetCommand::DoExecute()const
{
	if (!databaseManager)
	{
		Result failed;
		failed.status = false;
		failed.result = "ERROR: SetCommand::DoExecute() databaseManager is not set!! , SET command ignored!\n";
		return failed;
	}
	return databaseManager->SetSetting(m_command.first, m_command.second);
}
