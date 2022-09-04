//
//  NodeTree.h
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#ifndef NodeTree_h
#define NodeTree_h

#include "Node.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <exception>
#include <vector>

using namespace liuyuan;

namespace liuyuan
{

class NodeTree
{
private:
	std::shared_ptr<Node> _root;			
	std::weak_ptr<Node> _cur_node;
public:
	NodeTree();
	NodeTree(const NodeTree& other) = delete;
	~NodeTree() = default;

	inline shared_ptr<const Node> get_root() const { return _root; }
	inline shared_ptr<Node> get_cur_node() const { return _cur_node.lock(); }
	
	inline void set_cur_node(const shared_ptr<Node>& new_node) { this->_cur_node = new_node; }
};

}
#endif /* NodeTree_h */
