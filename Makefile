main:main.o libstack.so libqueue.so
	g++ -fkeep-inline-functions -o main main.o -L /lib -I. -lstack -lqueue
main.o:main.cpp queue.h stack.h
	g++ -c main.cpp -o main.o
libstack.so:libstack.o
	g++ -o libstack.so libstack.o -shared -fPIC
	cp libstack.so /lib
libqueue.so:libqueue.o
	g++ -o libqueue.so libqueue.o -shared -fPIC
	cp libqueue.so /lib
libstack.o:libstack.cpp
	g++ -o libstack.o -c libstack.cpp -fPIC
libqueue.o:libqueue.cpp queue.h
	g++ -o libqueue.o -c libqueue.cpp -fPIC
clean:
	rm -f *.o main

	
