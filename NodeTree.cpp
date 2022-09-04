//
//  NodeTree.cpp
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#include "NodeTree.h"
#include "Node.h"
#include "tool.h"
#include <cstring>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace liuyuan
{
	NodeTree::NodeTree() :
		_root(new Node("root", nullptr, D)),
		_cur_node(_root) 
	{
	}

}
	
