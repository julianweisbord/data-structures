default: prog

linkedList.o: linkedList.h linkedList.c
	gcc -Wall -g -std=c99 -c linkedList.c

testLinkedList.o: linkedListMain.c testLinkedList.c
	gcc -Wall -g -std=c99 -c linkedListMain.c testLinkedList.c

prog: linkedList.o testLinkedList.o
	gcc -Wall -g -std=c99 -o prog linkedList.o testLinkedList.o

clean:
	rm linkedList.o
	rm testLinkedList.o
	rm prog
