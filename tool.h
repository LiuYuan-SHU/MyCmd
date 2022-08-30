#ifndef _TOOL_
#define _TOOL_

#include <string>
#include <ctime>

using std::string;
using std::time_t;
using std::time;
using std::ctime;

namespace liuyuan
{
	inline const string get_cur_date()
	{
		time_t cur_time = time(nullptr);
		return string(ctime(&cur_time));
	}

}

#endif
