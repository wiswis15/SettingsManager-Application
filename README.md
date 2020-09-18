# SettingsManager-Application

SettingsManager-Application is an application that provides the user with an easy way to save,retrieve and delete settings/information on their computer.  
Example:  
SET myBanKAccount mybankAcoountNumber    : myBanKAccount is saved  
GET myBanKAccount : will display mybankAcoountNumber  

The information is saved into a file, at the same level of the execution binary,Eventually, you can personalize the path by changing  the value of the variable settingsFile inside Definition.h


## Installation

You can use the binary files already in the bin directory.

You can also easily build it , using CMAKE. All the CMAKE files are there.

## Usage    
-SET myname Test    
OK  
-SET myinformation1 value1  
OK  
-DELETE myinformation1  
OK  
-help  
These are the available commands:  
SET key value  
GET key  
DELETE key  

## Adding More Commands
1- main.cpp update commandsList with the name of the new command
2- SettingsManager.cpp create a function to handle your new commands, you can combine the existing ones
3- main.cpp : add the call of the newcly created function
4- Create a class  that inherits CommandIface and implements the functions ReadArguments and DoExecute.
  ReadArguments is responsible to check the arguments specific for the new command
  DoExecute  is the real execution of the command
5- Update  DataBaseManagerIface with a new pure virtual function
6- Add the new Command type to the CommandFactory class
  
 ## Adding More DataBasaeManagers(exmple SQL or saving Data in ElasticSearch)
 1- Create a new class that inherits DataBaseManagerIface. For example see class FileDataBaseManager
 2- Implements all the pure function with the real logic of the new database manager
 3  Create an instance of the new class inside SettingsManager class
 4- Adjust the function callls inside SettingsManager
 
