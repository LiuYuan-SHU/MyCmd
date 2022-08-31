make_cmd = g++ -c -Wall -std=c++11
objects = main.o Node.o NodeTree.o tool.o

edit : $(objects)
	g++ -o MyCmd $(objects) -Wall -std=c++11

main.o : main.cpp 
	$(make_cmd) main.cpp

Node.o : Node.cpp Node.h tool.h tool.cpp global.h
	$(make_cmd) Node.cpp

NodeTree.o : NodeTree.cpp NodeTree.h Node.cpp Node.h tool.h tool.cpp global.h
	$(make_cmd) NodeTree.cpp

tool.o : tool.h
	$(make_cmd) tool.cpp

clean:
	-rm *.o

debug_all:
	g++ -Wall -o MyCmd_debug *.cpp ./Test/*.cpp -DDEBUG=1 -DTEST_NODE -DTEST_TREE -DTEST_TOOL -std=c++11

debug_node:
	g++ -Wall -o MyCmd_debug_node *.cpp ./Test/test_node.cpp -DDEBUG=1 -DTEST_NODE -std=c++11

debug_tree:
	g++ -Wall -o MyCmd_debug_tree *.cpp ./Test/test_node_tree.cpp -DDEBUG=1 -DTEST_TREE -std=c++11

debug_tool:
	g++ -Wall -o MyCmd_debug_tool *.cpp ./Test/test_tool.cpp -DDEBUG=1 -DTEST_TOOL -std=c++11


