//
//  Node.h
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/30.
//
//  This head file declares the basic Tree Node for
//  the file system tree.
//  For data members, you should notice that, the
//  pointer points the parent and sibling node has
//  no key word `mutable`, which means if you define
//  a const Node, you can't modify its parent and
//  sibling. This trait is designed for root.

#ifndef _NODE_
#define _NODE_

#include <stdexcept>
#include <string>
#include <memory>
#include <exception>
#include <typeinfo>

using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;

namespace liuyuan
{

typedef bool NODE_TYPE;
constexpr bool F = true;
constexpr bool D = false;

class Node : std::enable_shared_from_this<Node>
{
private:
    mutable string _node_name;
    NODE_TYPE _node_type;
    string _create_date;
    string _create_user;
    shared_ptr<Node> _parent;
    shared_ptr<Node> _sibling;
    mutable shared_ptr<Node> _child;
public:
    Node(const string& node_name, const shared_ptr<Node>& parent = nullptr, NODE_TYPE node_type = liuyuan::F);
    Node(const string& node_name, const Node& parent, NODE_TYPE node_type = liuyuan::F);
	Node(const Node& other);
	~Node();

	inline void set_node_name(const string& node_name) { this->_node_name = node_name; }
	inline void set_parent(const Node& parent) { set_parent(make_shared<Node>(parent)); }
	inline void set_parent(const shared_ptr<Node>& parent) { this->_parent = parent; }
	inline void set_sibling(const Node& sibling) { set_sibling(make_shared<Node>(sibling)); }
	inline void set_sibling(const shared_ptr<Node>& sibling) { this->_sibling = sibling; }
	inline void set_child(const Node& child) const { set_child(make_shared<Node>(child)); }
	void set_child(const shared_ptr<Node>& child) const throw (std::bad_typeid);

	inline const string& get_node_name() const { return this->_node_name; }
	inline NODE_TYPE get_node_type() const { return this->_node_type; }
	inline const string& get_create_date() const { return this->_create_date; }
	inline const string& get_create_user() const { return this->_create_user; }
	inline const weak_ptr<Node> get_parent() const { return this->_parent;  }
	inline const shared_ptr<Node> get_sibling() const { return this->_sibling; }
	inline const shared_ptr<Node> get_child() const { return this->_child; }
	shared_ptr<Node> get_node(const string& child_name, NODE_TYPE node_type = liuyuan::D) const;

	shared_ptr<Node> change_node(const string& node_name, NODE_TYPE node_type = liuyuan::D) throw(std::invalid_argument);
	const string toString();
};

}

#endif
