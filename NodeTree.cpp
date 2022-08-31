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

	shared_ptr<Node> NodeTree::change_dir(const std::string &path) throw(std::invalid_argument, std::out_of_range)
	{
		std::vector<string> node_name = liuyuan::divide_path(path);
		string first_node = node_name.at(0);
		weak_ptr<Node> ite;
		if (first_node == "root")
		{
		}
		else if (first_node == ".")
		{
		}
		else
		{
			std::ostringstream buffer;
			buffer << "wrong node name in " << __func__ << "with name " << first_node << std::endl;
			throw std::invalid_argument(buffer.str());
		}

		return ite.lock();
	}
}
