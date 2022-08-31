#ifndef _TOOL_
#define _TOOL_

#include <stdexcept>
#include <string>
#include <ctime>
#include <vector>

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

	std::vector<std::string> divide_path(const std::string& path) throw(std::invalid_argument, std::out_of_range);
}

#endif
