#include "Node.h"
#if DEBUG
#include "./Test/test_node.h"
#endif
#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

using namespace liuyuan;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::pair;

int main()
{
#if DEBUG
	// liuyuan::test::TEST_INFO result = liuyuan::test::test_CST_DST_setters();
	// liuyuan::test::TEST_INFO result = liuyuan::test::test_const_node();
	// liuyuan::test::TEST_INFO result = liuyuan::test::test_insert_child_for_file_node();
	
	if (!result.first) { cout << result.second << endl; }
#endif
}


