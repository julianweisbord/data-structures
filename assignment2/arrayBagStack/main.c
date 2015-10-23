#include <stdio.h>
#include <stdlib.h>
#include "arrayBagStack.h"

int main (int argc, const char * argv[]) {

    struct arrayBagStack *myBag;


	myBag = createArray();

	initArray(myBag);

	addArray(myBag, 1);
	addArray(myBag, 3);
	removeArray(myBag,1);
	//pushArray(myBag, 1);
	//pushArray(myBag, 2);

	int res = containsArray(myBag,1);

	if(res > 0)
		printf("Contained 1 \n");
	else printf("Did not contain a 1\n");

	res = containsArray(myBag, 3);

	if(res > 0)
		printf("Contained a 3\n");
	else printf("Did not contain 3\n");
	return(0);

}
