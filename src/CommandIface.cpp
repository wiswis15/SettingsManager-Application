#include "CommandIface.h"

using namespace std;


/*! \fn CommandIface::Execute(const string& arguments) 
 *  \brief Execute command 
 *  \param arguments : command arguments
 *  \return the result of the command 
 */
Result CommandIface::Execute(const string& arguments) 
{
	auto result=ReadArguments(arguments);// first read the command's arguments
	if (!result.status)
	{	// Error in input arguments
		return result;
	}
	return DoExecute();// execute it
}


/*! \fn CommandIface::SetDatabaseManager(DataBaseManagerIface* manager)
 *  \brief set the database command's handler
 *  \param manager : database manager who will handle the command
 */
void CommandIface::SetDatabaseManager(DataBaseManagerIface* manager)
{
	databaseManager = manager;
}
