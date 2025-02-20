testll: testLL.o
	g++ -o testll testLL.o

testLL.o: testLL.cpp CLinkedList.h Node.h ListIterator.h
	g++ -c testLL.cpp

clean:
	\rm -f *.o testll
	\touch *