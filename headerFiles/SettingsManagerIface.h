#pragma once
#include <string>


/*
Interface class used to execute received commands.
*/
class SettingsManagerIface {
	
public:
	virtual ~SettingsManagerIface() {};
	virtual std::string GetSettings(std::string& name) = 0;
	virtual std::string SetSettings(std::string& name) = 0;
	virtual std::string DeleteSettings(std::string& name) = 0;


};