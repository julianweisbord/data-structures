default: prog2

dynamicArray.o: dynamicArray.h dynamicArray.c
	gcc -Wall -g -std=c99 -c dynamicArray.c

dynamicArrayMain.o: dynamicArrayMain.c
	gcc -Wall -g -std=c99 -c dynamicArrayMain.c

prog2: dynamicArray.o dynamicArrayMain.o
	gcc -Wall -g -std=c99 -o prog2 dynamicArray.o dynamicArrayMain.o

clean:
	rm linkedList.o
	rm testLinkedList.o
	rm prog
