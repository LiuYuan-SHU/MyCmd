// 
//	test_node_tree.h
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//

#ifndef Test_Node_Tree_H
#define Test_Node_Tree_H

#include "test_global.h"

namespace liuyuan
{
	namespace test
	{
		// 测试文件树的构造、析构函数
		TEST_INFO test_tree_CST_DST();

		// 测试文件树的set_cur_node 函数
		TEST_INFO test_tree_set_cur_node();

		// 测试函数数组
		constexpr TEST_INFO (*test_arr_tree[])() = { 
											test_tree_CST_DST,
											test_tree_set_cur_node
											};
	}
}


#endif
