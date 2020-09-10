#pragma once
#include <unordered_map>
#include "DataBaseManagerIface.h"
#include "Definitions.h"



/* Concrete class used when saving Data into a  file*/

class FileDataBaseManager : public DataBaseManagerIface
{

public:
	FileDataBaseManager(const std::string& path = settingsFile);
	void SetFileDatabasePath(const std::string& path);

protected:
	Result SetSetting(const std::string& key, const std::string& value)  final;
	Result GetSetting(const std::string& key) final;
	Result DeleteSetting(const std::string& key) final;

private:
	std::unordered_map<std::string, std::string> m_settings;
	std::string m_pathFile = "";
	bool LoadSettings();
	bool SaveSettings();

};

