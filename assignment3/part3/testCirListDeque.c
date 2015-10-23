#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


	/* Test your linked list in here! */

	printf("Hello from test code!\n");
  struct cirListDeque* q = createCirListDeque();
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("front val: %g\n", frontCirListDeque(q));
	printf("back val: %g\n", backCirListDeque(q));
  printf("Removing front...\n");
  removeFrontCirListDeque(q);
  printf("Removing back...\n");
	removeBackCirListDeque(q);
	printCirListDeque(q);
  printf("reverse list ...\n");
	reverseCirListDeque(q);
	// printCirListDeque(q);
	return 0;
}
