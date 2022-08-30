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

pair<TEST_STATUS, string> test_CST_DST_setters();
}
}

#endif /* test_node_h */
