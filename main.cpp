#include "Node.h"

#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

#if DEBUG
	#ifdef TEST_NODE
	#include "./Test/test_node.h"
	#endif

	#ifdef TEST_TREE
	#include "./Test/test_node_tree.h"
	#endif

	#ifdef TEST_TOOL
	#include "./Test/test_tool.h"
	#endif

	#define TEST_ARR(ARR_NAME) \
		std::cout << #ARR_NAME << std::endl; \
		for (size_t index = 0; index < sizeof(ARR_NAME) / sizeof(*ARR_NAME); index++) \
		{ \
			TEST_INFO result = ARR_NAME[index](); \
			if (result.first == FAIL) \
				std::cout << result.second << std::endl; \
		} \
		std::cout << std::endl;

#endif

#if DEBUG
	using liuyuan::test::TEST_INFO;
	using liuyuan::test::SUCCESS;
	using liuyuan::test::FAIL;
	#ifdef TEST_NODE
		using liuyuan::test::test_arr_node;
	#endif
	#ifdef TEST_TREE
		using liuyuan::test::test_arr_tree;
	#endif
	#ifdef TEST_TOOL
		using liuyuan::test::test_arr_tool;
	#endif
#endif
using std::cout;
using std::endl;
using std::shared_ptr;
using std::pair;
namespace liuyuan 
{
	void debug();
}

int main()
{
#if !DEBUG
#elif DEBUG
	liuyuan::debug();
#endif
}

void liuyuan::debug()
{
#ifdef TEST_NODE
		TEST_ARR(test_arr_node)
	#endif

	#ifdef TEST_TREE
		TEST_ARR(test_arr_tree)
	#endif

	#ifdef TEST_TOOL
		TEST_ARR(test_arr_tool)
#endif
}
