#include "Node.h"
#if DEBUG
#include "./Test/test_node.h"
#endif
#include <cstddef>
#include <iostream>
#include <memory>

using namespace liuyuan;
using std::cout;
using std::endl;
using std::shared_ptr;

int main()
{
#if DEBUG
	liuyuan::test::test_CST_DST_setters();
#endif
}


