testqueue: testqueue.o myqueue.o
	g++ -o testqueue -g testqueue.o myqueue.o

testqueue.o: testqueue.cpp myqueue.h
	g++ -g -c -Wall testqueue.cpp

myqueue.o: myqueue.cpp
	g++ -g -c -Wall myqueue.cpp

clean:
	del -f *.o testqueue
