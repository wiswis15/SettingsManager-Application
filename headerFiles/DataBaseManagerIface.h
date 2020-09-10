#pragma once
#include "Definitions.h"


/* Abstract class to communicate with any DataBAseManager concrete class,inherit it for any further
	DataBaseManager(example sql database...)
*/

class DataBaseManagerIface
{
public:
	virtual ~DataBaseManagerIface() {};

	virtual Result SetSetting(const std::string& key, const std::string& value) = 0;
	virtual Result GetSetting(const std::string& key) = 0;
	virtual Result DeleteSetting(const std::string& key) = 0;

};

