// 
//	test_tool.cpp
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//

#include "test_global.h"
#include "test_tool.h"
#include "../tool.h"
#include <algorithm>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <iostream>

namespace liuyuan
{
	namespace test
	{
		TEST_INFO test_tool_get_cur_date()
		{
			string cur_date = get_cur_date();
			std::cout << cur_date << std::endl;
			return std::make_pair(SUCCESS, cur_date);
		}

		TEST_INFO test_tool_divide_path()
		{
			try
			{
				string test_str_1 = "./test_global.h";
				string test_str_2 = "/Users/liuyuan/Liuyuan/GithubRepositories/MyCmd";
				string test_str_3 = "../MyCmd/Node.h";
				string test_str_4 = ".//.//";
				
				string test_strs[] = { test_str_1, test_str_2, test_str_3, test_str_4 };
				for(string str: test_strs)
				{
					std::cout << "origin string:\t" << str << std::endl; 
					std::vector<string> result = divide_path(str);
					std::for_each(result.begin(), 
									result.end(), 
									[](const string &s)
										{ std::cout << s << " "; });
					std::cout << std::endl << std::endl;
				}

				return std::make_pair(SUCCESS, "");
			}
			catch(std::invalid_argument e)
			{
				return std::make_pair(FAIL, e.what());
			}
			catch(std::out_of_range e)
			{
				return std::make_pair(FAIL, e.what());
			}

		}
	}
}
