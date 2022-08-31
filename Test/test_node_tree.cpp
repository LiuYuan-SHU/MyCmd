//
//	test_node_tree.cpp
//	MyCmd
//
//	Created by Liu Yuan on 2022/8/31
//

#include "../NodeTree.h"
#include "test_node_tree.h"
#include "test_global.h"
#include <utility>

namespace liuyuan
{
	namespace test
	{
		TEST_INFO test_tree_CST_DST()
		{
			liuyuan::NodeTree tree;		
			return std::make_pair(SUCCESS, "");
		}

		TEST_INFO test_tree_set_cur_node()
		{
			liuyuan::NodeTree tree;
			tree.set_cur_node(tree.get_cur_node());
			return std::make_pair(SUCCESS, "");
		}
		
	}
}
