#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// double getMilliseconds() {
//    return 1000.0 * clock() / CLOCKS_PER_SEC;
// }

int main(int argc, char* argv[]) {

	/* Test your linked list in here! */

	printf("Hello from test code!\n");

  struct linkedList *b;
  int n, i;
  double t1, t2;

  for(n=0; n < 10; ++n) /* outer loop */
  {

    b = createLinkedList();

    for( i = 0 ; i < n; i++) {
          addList(b, (TYPE)i); /*Add elements*/
    }
    _printList(b);
    // t1 = getMilliseconds();/*Time before contains()*/

    for(i=0; i<n; i++) {
          containsList(b, i);
    }

    // t2 = getMilliseconds();/*Time after contains()*/

    printf("Time for running contains() ms\n");

    /* delete DynArr */
    deleteLinkedList(b);
  }
  return 0;
}
