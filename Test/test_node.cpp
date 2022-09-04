//
//  test_node.cpp
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#include "test_global.h"
#include "test_node.h"
#include "../Node.h"
#include <exception>
#include <iostream>
#include <memory>
#include <utility>

using std::exception;
using std::make_pair;

namespace liuyuan
{
namespace test
{

TEST_INFO test_CST_DST_setters()
{
    try
    {
        std::unique_ptr<Node> root(new Node("root", nullptr, D));
        root->set_sibling(make_shared<Node>("sibling"));
        root->set_child(make_shared<Node>("child", *root, liuyuan::F));
    }
    catch (exception e)
    {
        return make_pair(FAIL, e.what());
    }
    return make_pair(SUCCESS, "");
}

TEST_INFO test_const_node()
{
	try
	{
		shared_ptr<const Node> root(new Node("root", nullptr, liuyuan::D));
		root->set_child(make_shared<Node>("child"));
		std::cout << "child add for const root successfully" << std::endl;
		// root->set_sibling(make_shared<Node>("sibling"));
		std::cout << "sibling add for const root successfully" << std::endl;
	}
	catch (exception e)
	{
		return make_pair(FAIL, e.what());
	}
	return make_pair(SUCCESS, "");
}

TEST_INFO test_insert_child_for_file_node()
{
	try
	{
		shared_ptr<Node> file_node(new Node("file"));
		file_node->set_child(make_shared<Node>("illegal child"));
	}
	catch (std::bad_typeid e)
	{
		return make_pair(FAIL, e.what());
	}
	return make_pair(SUCCESS, "");
}

TEST_INFO test_change_node()
{
		shared_ptr<Node> root(new Node("root", nullptr, liuyuan::D));
		root->set_child(shared_ptr<Node>(new Node("child1", nullptr, liuyuan::D)));
		root->get_child()->set_child(shared_ptr<Node>(new Node("child2")));

		auto child1 = root->get_child();
		std::cout << child1->change_node("..")->toString() << std::endl;
		std::cout << child1->change_node(".")->toString() << std::endl;
		std::cout << child1->change_node("child2")->toString() << std::endl;
		return make_pair(SUCCESS, "");
}

}
}
