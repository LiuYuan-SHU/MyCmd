//
//  NodeTree.cpp
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/30.
//

#include "Node.h"
#include "global.h"
#include "tool.h"
#include <cstdio>
#include <memory>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

using std::endl;
using std::ostringstream;
using namespace liuyuan;

namespace liuyuan
{
	Node::Node(const string& node_name, const shared_ptr<Node>& parent, NODE_TYPE node_type):
		_node_name(node_name),
		_node_type(node_type),
		_create_date(get_cur_date()),
		_create_user(WHO_AM_I),
		_parent(parent),
		_sibling(nullptr),
		_child(nullptr)
	{
	}

	Node::Node(const string& node_name, const Node& parent, NODE_TYPE node_type):
		_node_name(node_name),
		_node_type(node_type),
		_create_date(get_cur_date()),
		_create_user(WHO_AM_I),
		_parent(std::make_shared<Node>(parent)),
		_sibling(nullptr),
		_child(nullptr)
	{
	}

	Node::Node(const Node& other):
		_node_name(other._node_name),
		_node_type(other._node_type),
		_create_date(get_cur_date()),
		_create_user(WHO_AM_I),
		_parent(shared_ptr<Node>(nullptr)),
		_sibling(nullptr),
		_child(nullptr)
	{
	}

	Node::~Node()
    {
#if DEBUG
        std::printf("============================================\n");
        std::cout << this->toString();
        std::printf("--------------------------------------------\n");
#endif
		if (this->_sibling != nullptr)
        {
#if DEBUG
            std::cout << "sibling ptr use count: " << this->_sibling.use_count() << std::endl;
#endif
            this->_sibling.reset();
        }
		if (this->_child != nullptr)
        {
#if DEBUG
            std::cout << "child ptr use count:  " << this->_child.use_count() << std::endl;
#endif
            this->_child.reset();
        }
#if DEBUG
        std::printf("============================================\n\n");
#endif
	}

	void Node::set_child(const shared_ptr<Node>& child) const throw(std::bad_typeid)
	{
		if (this->_node_type == liuyuan::F) 
		{
			throw std::bad_typeid();
		}
		this->_child = child;
		child->set_parent(*this);
	}

	shared_ptr<Node> Node::get_node(const string& child_name, NODE_TYPE node_type) const
	{
		shared_ptr<Node> ite = this->get_child();
		while (ite)
		{
			if (ite->get_node_name() == child_name && node_type == ite->get_node_type()) { return ite; }
			ite = ite->get_sibling();
		}
		return make_shared<Node>(nullptr);
	}

	shared_ptr<Node> Node::change_node(const string &node_name, NODE_TYPE node_type) throw(std::invalid_argument)
	{
		if (node_name == ".") { return shared_from_this(); }
		else if (node_name == "..") { return (this->_parent ? this->_parent : throw std::invalid_argument("invalid directory ..")); }
		
		shared_ptr<Node> child = this->get_node(node_name, node_type);	
		if (child) { return child; }
		else 
		{
			ostringstream buffer;
			buffer << "so such node " << node_name << " with node type " << (node_type ? "FILE" : "DIR");
			throw std::invalid_argument(buffer.str());
		}
	}

	const string Node::toString()
	{
		ostringstream buffer;
		buffer << "Node Name\t" << this->_node_name << endl;
		buffer << "Node Type\t" << (this->_node_type ? "FILE" : "DIR")<< endl;
        buffer << "Create Date\t" << this->_create_date;
		buffer << "Create User\t" << this->_create_user << endl;
		return buffer.str();
	}
}
