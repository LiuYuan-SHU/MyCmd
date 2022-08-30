//
//  test_node.cpp
//  MyCmd
//
//  Created by Liu Yuan on 2022/8/31.
//

#include "test_node.h"
#include "../Node.h"
#include <exception>
#include <utility>

using std::exception;

namespace liuyuan
{
namespace test
{

pair<TEST_STATUS, string> test_CST_DST_setters()
{
    try
    {
        std::unique_ptr<Node> root(new Node("root", nullptr, DIR));
        root->set_sibling(make_shared<Node>("sibling"));
        root->set_child(make_shared<Node>("child", *root, liuyuan::FILE));
    }
    catch (exception e)
    {
        return make_pair(FAIL, e.what());
    }
    return make_pair(SUCCESS, "");
}

}

}
