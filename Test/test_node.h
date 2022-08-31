//
//  test_node.h
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#ifndef test_node_h
#define test_node_h

#include <utility>
#include <string>

using std::pair;
using std::make_pair;
using std::string;

namespace liuyuan
{
namespace test
{
typedef bool TEST_STATUS;
constexpr bool FAIL = false;
constexpr bool SUCCESS = true;

typedef std::pair<TEST_STATUS, std::string> TEST_INFO;

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

}
}

#endif /* test_node_h */
