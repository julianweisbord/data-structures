default: prog3

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog3: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog3 cirListDeque.o testCirListDeque.o

clean:
	rm cirListDeque.o
	rm testCirListDeque.o
