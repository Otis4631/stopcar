main:main.o libstack.so libqueue.so
	gcc -o main main.o -L. -lstack -lqueue
main.o:main.cpp queue.h stack.h
	gcc -c main.cpp -o main.o
libstack.so:libstack.o
	gcc -o libstack.so libstack.o -shared -fPIC
	cp libstack.so /lib
libqueue.so:libqueue.o
	gcc -o libqueue.so libqueue.o -shared -fPIC
	cp libqueue.so /lib
libstack.o:libstack.cpp
	gcc -o libstack.o -c libstack.cpp -fPIC
libqueue.o:libqueue.cpp queue.h
	gcc -o libqueue.o -c libqueue.cpp -fPIC
clean:
	rm -f *.o main

	
