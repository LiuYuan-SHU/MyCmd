//
//  test_node.h
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#ifndef test_node_h
#define test_node_h

#include "test_global.h"

namespace liuyuan
{
namespace test
{
// 测试构造函数、析构函数和set函数
// 测试本函数，应当通过
TEST_INFO test_CST_DST_setters();

// 测试const节点设置兄弟节点、孩子节点
// 测试前需要将注释去除
// 测试本函数，应当无法编译通过
TEST_INFO test_const_node();

// 测试为FILE节点添加子节点
// 测试本函数，应当抛出异常，即TEST_INFO.first应当为FAIL
TEST_INFO test_insert_child_for_file_node();

// 测试Node节点的find_child change_node函数
TEST_INFO test_change_node();

// 测试函数数组
constexpr TEST_INFO (*test_arr_node[])() = {	
												// test_CST_DST_setters,
												// test_const_node,
												test_change_node
											};

}
}

#endif /* test_node_h */
