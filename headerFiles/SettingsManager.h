#pragma once
#include <memory>
#include "SettingsManagerIface.h"
#include "FileDataBaseManager.h"
#include "CommandFactory.h"
#include "Definitions.h"




/* Main class responsable for treating all the received commands. 
This class can be easily expandable to integrate more ways of saving data(example: save it into an sql database)
*/

class SettingsManager : 	public SettingsManagerIface
{
public:
	SettingsManager(const std::string& fileSettingsPath = settingsFile);

private:
	CommandFactory m_command_factory;
	void SetFileSettingsPath(const std::string& path);
	std::string GetSettings(std::string& name) final;
	std::string SetSettings(std::string& name) final;
	std::string DeleteSettings(std::string& name) final;


	std::string m_fileSettingsPath = "";
	std::shared_ptr<DataBaseManagerIface> m_FiledataBaseManager;


};

