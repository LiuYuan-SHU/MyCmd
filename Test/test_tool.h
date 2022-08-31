//
//	test_tool.h
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//

#ifndef Test_Tool_H
#define Test_Tool_H

#include "test_global.h"

namespace liuyuan
{
	namespace test
	{
		// 测试获得当前日期函数
		// 如果正确运行，会打印当前日期，并且返回<SUCCESS, 当前日期>
		TEST_INFO test_tool_get_cur_date();

		// 测试文件路径分割
		// 如果正确运行，会打印路径，并且最后一个抛出异常
		TEST_INFO test_tool_divide_path();

		// 测试函数数组
		constexpr TEST_INFO (*test_arr_tool[])() = {
														test_tool_get_cur_date,
														test_tool_divide_path
													};
	}
}

#endif
