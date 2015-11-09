#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/

	if(((struct pizza*)left)->numToppings < ((struct pizza*)right)->numToppings){
		return -1;
	}
	else if(((struct pizza*)left)->numToppings > ((struct pizza*)right)->numToppings){
		return 1;
	}
	else if(((struct pizza*)left)->numToppings == ((struct pizza*)right)->numToppings){
		return 0;
	}

}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/
	assert(curval!=NULL);
	struct pizza* current = (struct pizza*) curval;
 	printf("%d\n", current->numToppings);

}
