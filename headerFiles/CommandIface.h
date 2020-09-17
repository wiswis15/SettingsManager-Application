#pragma once
#include "Definitions.h"
#include "DataBaseManagerIface.h"



/* Abstract class to be used when using commands objects */

class CommandIface
{
public:
	Result Execute(const std::string& arguments) ;
	void SetDatabaseManager(DataBaseManagerIface* manager);
	virtual ~CommandIface() {};

protected:
	CommandType m_type;
	DataBaseManagerIface* databaseManager=nullptr;
	virtual Result ReadArguments(const std::string& arguments)  = 0 ;// Any concrete class must implement its function to check and read arguments
	virtual Result DoExecute() const = 0;// Any concrete class must implement the execution logic
};

