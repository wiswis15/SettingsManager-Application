#include "FileDataBaseManager.h"
#include <fstream>
#include <iostream>

using namespace std;

/*!
 *  Constructor of FileDataBaseManager
 */
FileDataBaseManager::FileDataBaseManager(const string& path) : m_pathFile(path)
{
	LoadSettings();

}


/*! \fn FileDataBaseManager::SetFileDatabasePath
 *  \brief set settings file
 *  \param path : new settings file
 */
void FileDataBaseManager::SetFileDatabasePath(const string& path)
{
	m_pathFile = path;
}


/*! \fn FileDataBaseManager::GetSetting
 *  \brief get the setting with key from the settings file on disk
 *  \param key : key of the setting to get
 *  \return the result.
 */
Result FileDataBaseManager::GetSetting(const string& key)
{
	Result result;
	try
	{
		if (m_settings.find(key) != m_settings.end())
		{
			result.result = m_settings[key];
		}

	}
	catch (...)
	{
		result.status = false;
		result.result += "Error in FileDataBaseManager::GetSetting \n";

	}
	
	return result;
}


/*! \fn FileDataBaseManager::SetSetting
 *  \brief set the setting with key to the value. If key exists, it will override it.
 *  \param key : key of the setting to set
 *  \param value : value of the setting
 *  \return the result.
 */
Result FileDataBaseManager::SetSetting(const string& key, const string& value)
{
	Result result;
	if(key.empty())
	{
		result.status=false;
		result.result="Error, key can not be empty!\n";
		return result;
	}

	try
	{
		if (m_settings.find(key) != m_settings.end())
		{
			m_settings[key] = value;

		}

		m_settings[key] = value;
		SaveSettings();// update File as well
	}
	catch (...)
	{
		result.status = false;
		result.result += "FileDataBaseManager::SetSetting \n";

	}
	result.result = commandSuccesful;
	return result;

}


/*! \fn FileDataBaseManager::DeleteSetting
 *  \brief delete the setting with the key, if it exists
 *  \param key : key of the setting to delete
 *  \return the result.
 */
Result FileDataBaseManager::DeleteSetting(const string& key)
{
	Result result;
	try
	{
		if (m_settings.find(key) != m_settings.end())
		{
			m_settings.erase(key);
			SaveSettings();
		}
		else
		{
			result.result += " setting : " + key + " does not exist! \n";
			return result;
		}
	}
	catch (...)
	{
		result.status = false;
		result.result += "FileDataBaseManager::DeleteSetting \n";
	}
	result.result = commandSuccesful;
	return result;
}


/*! \fn FileDataBaseManager::LoadSettings()
 *  \brief load the settings from File
 *  \return false if failed, else, return true
 */
bool FileDataBaseManager::LoadSettings()
{
	try
	{
		std::ifstream settingsFile(m_pathFile, ifstream::out);
		if (settingsFile.is_open())
		{
			for (string line; getline(settingsFile, line); )
			{
				size_t positionSpace = line.find_first_of(" ");
				string key = line.substr(0, positionSpace);
				string value = line.substr(positionSpace + 1);
				m_settings[key] = value; // add all the values to the map values
			}

		}
	}
	catch (...)
	{
		cout << "Error while opening the settings File: " << m_pathFile << "\n";
		return false;
	}
	return true;
}

/*! \fn FileDataBaseManager::SaveSettings()
 *  \brief save the settings into the settings File in the disk
 *  \return false if failed, else, return true
 */
bool FileDataBaseManager::SaveSettings()
{
	try
	{
		ofstream newsettingsFile(m_pathFile);
		for (auto& setting : m_settings)
		{
			newsettingsFile << setting.first << " " << setting.second << "\n";// write all settings line by line
		}
	}
	catch (...)
	{
		cout << "Error while saving the settings File: " << m_pathFile << "\n";
		return false;
	}
	return true;
}
