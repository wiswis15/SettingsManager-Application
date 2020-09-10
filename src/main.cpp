//  This file is the entrance point for this application
//

#include <iostream>
#include <unordered_map>
#include <string>
#include "SettingsManager.h"
#include "Definitions.h"

using namespace std;



//Add any new command here
const std::unordered_map< string, CommandType> commandsList =
{
	{"help",CommandType::help},
	{"SET",CommandType::SET},
	{"GET",CommandType::GET},
	{"DELETE",CommandType::DELETE}

};




int main()
{
	std::unique_ptr < SettingsManagerIface >settingsManagerIface = std::make_unique<SettingsManager>();


	cout << "Welcome to KVPStorage! Type help for lost of commands \n";
	//read input data
	while (true)
	{
		string line;
		getline(std::cin, line);
		string firstWord = line.substr(0, line.find_first_of(" "));
		if (firstWord.empty())
		{
			cout << "Error: command can not be empty! \n";
		}
		else if (commandsList.find(firstWord) != commandsList.end())
		{
			auto arguments = line.substr(line.find_first_of(" ") + 1);
			switch (commandsList.at(firstWord))
			{
			case CommandType::help:
				cout << helpMessage << "\n";
				break;
			case CommandType::SET:
				cout << settingsManagerIface->SetSettings(arguments) << "\n";
				break;
			case CommandType::GET:
				cout << settingsManagerIface->GetSettings(arguments) << "\n";
				break;
			case CommandType::DELETE:
				cout << settingsManagerIface->DeleteSettings(arguments) << "\n";
				break;
			default:
				break;


			}
		}
		else
		{
			cout << "Error: " + firstWord + " is not a known command\n";
			cout << proposeHelpMessage;
		}


	}

	
}
