#pragma once
#include <string>

//This file contains the constants,settings and definitions needed across the application



const std::string settingsFile = "settingsFile!DoNotDelete";// This is the full path of the settings path, Change it as needed


const std::string commandSuccesful = "OK";
const std::string helpMessage = "These are the available commands:\nSET key value\nGET key\nDELETE key";
const std::string proposeHelpMessage = "Type help to get the available commands.\n";


const unsigned int max_CharKeys = 100;// arbitral max  characters for a key, change it if needed!
const unsigned int max_CharKeysValue = 100;// arbitral max  characters for a key, change it if needed!


enum class CommandType
{
	help = 1,
	SET =2,
	GET = 3,
	DELETE = 4	
};

// type of any command 's execution result
struct Result
{
	bool status = true;
	std::string result;
};

