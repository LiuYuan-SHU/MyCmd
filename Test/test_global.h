//
//	test_global.h
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//
 
#ifndef Test_Global_H
#define Test_Global_H

#include <utility>
#include <string>

using std::pair;
using std::string;

namespace liuyuan
{
	namespace test
	{
		typedef bool TEST_STATUS;
		constexpr bool FAIL = false;
		constexpr bool SUCCESS = true;

		typedef std::pair<TEST_STATUS, std::string> TEST_INFO;
	}
}

#endif
