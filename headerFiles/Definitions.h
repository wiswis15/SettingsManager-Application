#pragma once
#include <string>

//This file contains the constants,settings and definitions needed across the application



const std::string settingsFile = "mysettings.txt";
const std::string commandSuccesful = "OK";
const std::string helpMessage = "These are the available commands:\nSET key value\nGET key\nDELETE key";
const std::string proposeHelpMessage = "Type help to get the available commands.\n";


const unsigned int max_CharKeys = 100;// max  characters for a key
const unsigned int max_CharKeysValue = 100;// max  characters for a key


enum class CommandType
{
	help = 1,
	SET =2,
	GET = 3,
	DELETE = 4	
};


struct Result
{
	bool status = true;
	std::string result;
};

