#include "SettingsManager.h"


using namespace std;


/*!
 *  Constructor of SettingsManager
 */
SettingsManager::SettingsManager(const string& fileSettingsPath) : m_fileSettingsPath(fileSettingsPath)
{
	m_FiledataBaseManager = std::make_shared<FileDataBaseManager>();
}

/*! \fn SettingsManager::SetFileSettingsPath(const string& path)
 *  \brief change the settings's filepath
 *  \param path : new file's path
 */
void SettingsManager::SetFileSettingsPath(const string& path)
{
	m_fileSettingsPath = path;
}

/*! \fn SettingsManager::GetSettings(string& name)
 *  \brief get the settings.  
 *  \return settings value or empty if settings is missing
 */
string SettingsManager::GetSettings(string& name)
{
	auto getCommand=m_command_factory.CreateCommand(CommandType::GET);
	getCommand->SetDatabaseManager(m_FiledataBaseManager.get());
	return getCommand->Execute(name).result;

}

/*! \fn SettingsManager::SetSettings(string& name)
 *  \brief set a new setting, or change it if it is already existing.
 *  \return OK if successfull, else an error message
 */
string SettingsManager::SetSettings(string& name)
{
	auto setCommand = m_command_factory.CreateCommand(CommandType::SET);
	setCommand->SetDatabaseManager(m_FiledataBaseManager.get());
	return setCommand->Execute(name).result;
}

/*! \fn SettingsManager::DeleteSettings(string& name)
 *  \brief delete a setting
 *  \return OK if successfull, else an error message
 */
string SettingsManager::DeleteSettings(string& name)
{
	auto deleteCommand = m_command_factory.CreateCommand(CommandType::DELETE);
	deleteCommand->SetDatabaseManager(m_FiledataBaseManager.get());
	return deleteCommand->Execute(name).result;
}
