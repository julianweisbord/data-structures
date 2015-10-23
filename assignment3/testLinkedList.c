#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
	/* Test your linked list in here! */

	printf("Hello from test code!\n");

	struct linkedList *ll = createLinkedList();

  printf("\nTesting addBackList...\n");
  printf("Adding 4 to back...\n");
  addBackList(ll, 4);
  printf("Adding 2 to back...\n");
  addBackList(ll, 2);
  printf("The lists contents:\n");
  _printList(ll);

  printf("\nTesting addFrontList...\n");
  printf("Adding 32 to front...\n");
  addFrontList(ll, 32);
  printf("Adding 7 to front...\n");
  addFrontList(ll, 7);
  printf("The lists contents:\n");
  _printList(ll);



  printf("\nTesting removeFrontList...\n");
  printf("Removing 7 from front...\n");
  removeFrontList(ll);
  // test(sizeLinkedList(ll) == 3, "Removed one element");
  // test(frontList(ll) == 32, "Front should be 32");
  printf("The lists contents:\n");
  _printList(ll);

  printf("\nTesting removeBackList...\n");
  printf("Removing 2 from back...\n");
  removeBackList(ll);
  // test(sizeLinkedList(ll) == 2, "Removed one element");
  // test(backList(ll) == 4, "Back should be 4");
  printf("The list contents:\n");
  _printList(ll);

  printf("\nTesting removeList...\n");
  printf("Removing 32 from list...\n");
  removeList(ll, 32);
	_printList(ll);
  // test(sizeLinkedList(ll) == 1, "Removed one element");
  printf("Removeing 4 from list...\n");
  removeList(ll, 4);
  // test(isEmptyList(ll), "List is now empty");
  printf("List is empty but will print list anyway: \n");
	_printList(ll);
  return 0;
}
