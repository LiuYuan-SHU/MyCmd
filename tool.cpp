//
//	tool.cpp
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//

#include "tool.h"
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>

namespace liuyuan
{
	std::vector<std::string> divide_path(const std::string &path) throw(std::invalid_argument, std::out_of_range)
	{
		char* origin_str = const_cast<char*>(path.c_str());		
		std::vector<string> node_name;

		if (path.at(0) == '/') { node_name.push_back("root"); }
		else { node_name.push_back("."); }
		char* substr = std::strtok(origin_str, "/");
		while(substr)
		{
			if (std::strcmp(substr, ""))
			{
				node_name.emplace_back(substr);
			}
			else
			{
				throw std::invalid_argument("wrong path");
			}

			substr = std::strtok(nullptr, "/");
		}	

		return node_name;
	}
}
