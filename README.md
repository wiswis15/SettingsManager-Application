# SettingsManager-Application

SettingsManager-Application is an application that provides the user with an easy way to save,retrieve and delete information/settings on their computer.  
Example:  
SET myBanKAccount mybankAcoountNumber   --> myBanKAccount is saved with the value  mybankAcoountNumberGET myBanKAccount : will display mybankAcoountNumber  

The information is saved into a file in the bin folder. Eventually, you can personalize the path by changing  the value of the variable settingsFile inside Definition.h

The build method is [CMake](https://cmake.org/).

## UNIX/LINUX - MacOS (terminal) - WINDOWS (cygwin, MinGW)

To build the application, type from the main path (where main.cpp is)
```
mkdir build
cd build
cmake ..
make
```
Binaries are then located in the 'bin' directory.

## Usage    

$ ./SettingsManager 

$ SET myname Test    
OK  
$ SET myinformation1 value1  
OK  
$ DELETE myinformation1  
OK  
$ help  
These are the available commands:  
SET key value  
GET key  
DELETE key  

## Adding more Commands
1- main.cpp :update commandsList with the name of the new command. <br/>
2- SettingsManager.cpp : create a function to handle your new commands, you can combine the existing ones.<br/> 
3- main.cpp : add the call of the newly created function.<br/> 
4- Create a class  that inherits CommandIface and implements the functions ReadArguments and DoExecute.<br/>
 ReadArguments is responsible to check the arguments specific for the new command.<br/>
 DoExecute  is the real execution of the command.<br/>
5- Update  DataBaseManagerIface with a new pure virtual function.<br/> 
6- Add the new Command type to the CommandFactory class.<br/> 
  
 ## Adding More DataBasaeManagers(exmple SQL or saving Data in ElasticSearch).<br/> 
 1- Create a new class that inherits DataBaseManagerIface. For example see class FileDataBaseManager.<br/> 
 2- Implements all interfaces with the desired logic of the new database manager.<br/> 
 3- Create an instance of the new class inside SettingsManager class.<br/> 
 4- Adjust accordingly the function calls inside SettingsManager.<br/> 
 
 
 ##  Design
 The folder Design contains a file class Diagram.pdf. The UML class diagram may be very helpful understanding the architecture of the application.
