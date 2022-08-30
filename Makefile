make_cmd = g++ -c -Wall -std=c++11
objects = main.o Node.o
objects_debug = main_debug.o Node_debug.o test_node.o

edit : $(objects)	
	g++ -o MyCmd $(objects)
	-./MyCmd

main.o : main.cpp 
	$(make_cmd) main.cpp

main_debug.o : main.cpp
	$(make_cmd) -DDEBUG=1 main.cpp -o main_debug.o

Node.o : Node.cpp Node.h tool.h global.h
	$(make_cmd) Node.cpp

Node_debug.o : Node.cpp Node.h tool.h global.h
	$(make_cmd) -DDEBUG=1 Node.cpp -o Node_debug.o

test_node.o : ./Test/test_node.cpp Node.cpp ./Test/test_node.h Node.h
	$(make_cmd) ./Test/test_node.cpp -DDEBUG=1

debug : $(objects_debug)
	g++ -o MyCmd_debug $(objects_debug) -DDEBUG=1
	-./MyCmd_debug

clean:
	-rm $(objects) $(objects_debug)
