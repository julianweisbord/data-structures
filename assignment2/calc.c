#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"

// example run is: ./calc 5 4 ^
// This would be 4^5 power

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	// main checks if there are less than 2 args
	if (sizeDynArr(stack) <2){
		printf("Not enough args!\n");
		exit(0);
	}
	double i =topDynArr(stack);
	popDynArr(stack);
	double j =topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, i+j);
	// }
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double i =topDynArr(stack);
	popDynArr(stack);
	double j =topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, i-j);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double i =topDynArr(stack);
	popDynArr(stack);
	double j =topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, i/j);
}
void multiply(struct DynArr *stack){
	double i =topDynArr(stack);
	popDynArr(stack);
	double j =topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, i*j);
}
void power(struct DynArr *stack){
	double i,j;
	i = topDynArr(stack);
	popDynArr(stack);
	j = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(i,j));
}
void square(struct DynArr*stack){
	double i= topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(i, 2));
}
void cube(struct DynArr*stack){
	double i= topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(i, 3));
}
void absolute(struct DynArr*stack){
	double i= topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, fabs(i));
}
void squareroot(struct DynArr*stack){
	double i = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack ,sqrt(i));
}
void exponent(struct DynArr*stack){
	double i = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack ,exp(i));

}
void ln(struct DynArr*stack){
	double i = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log(i));

}
void logar(struct DynArr *stack){
	double i = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log10(i));
}

void incorrect(struct DynArr *stack, char* arg){
	int size;

	if (isEmptyDynArr(stack) == 0)
		size = sizeDynArr(stack);
	else
		size = 0;


	printf("Invalid string: ");
	for (int i = 0; i < size; ++i){
		printf("%f ", getDynArr(stack, i));
	}
	printf("%s\n",arg);
	deleteDynArr(stack);
	exit(0);

}



double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++)
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0){
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=2){
				add(stack);
			}
			else{
				incorrect(stack,"+");
			}
		}
		else if(strcmp(s,"-") == 0){
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=2)
				subtract(stack);
			else{
				incorrect(stack,"-");
			}
		}
		else if(strcmp(s, "/") == 0){


			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=2)
				divide(stack);
			else{
				incorrect(stack,"/");
			}
		}
		else if(strcmp(s, "x") == 0){
			/* FIXME: replace printf with your own function */
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=2)
				multiply(stack);
			else{
				incorrect(stack,"x");
			}
		}

		else if(strcmp(s, "^") == 0){
			/* FIXME: replace printf with your own function */
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=2)
				power(stack);
			else{
				incorrect(stack,"^");
			}
		}
		else if(strcmp(s, "^2") == 0){
			/* FIXME: replace printf with your own function */
			// printf("Squaring\n");

			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				square(stack);
			else{
				incorrect(stack,"^2");
			}
		}
		else if(strcmp(s, "^3") == 0){
			/* FIXME: replace printf with your own function */
			// printf("Cubing\n");
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				cube(stack);
			else{
				incorrect(stack,"^3");
			}
		}
		else if(strcmp(s, "abs") == 0){
			/* FIXME: replace printf with your own function */
			// printf("Absolute value\n");

			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				absolute(stack);
			else{
				incorrect(stack,"abs");
			}
		}
		else if(strcmp(s, "sqrt") == 0){
			/* FIXME: replace printf with your own function */
			// printf("Square root\n");
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				squareroot(stack);
			else{
				incorrect(stack,"sqrt");
			}

		}
		else if(strcmp(s, "exp") == 0){
			/* FIXME: replace printf with your own function */
			// printf("Exponential\n");

			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				exponent(stack);
			else{
				incorrect(stack,"exp");
			}

		}
		else if(strcmp(s, "ln") == 0){
			/* FIXME: replace printf with your own function */
			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				ln(stack);
			else{
				incorrect(stack,"ln");
			}
		}
		else if(strcmp(s, "log") == 0){
			/* FIXME: replace printf with your own function */

			if(isEmptyDynArr(stack) ==0 && sizeDynArr(stack) >=1)
				logar(stack);
			else{
				incorrect(stack,"log");
			}
		}
		else{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if(strcmp(s, "e") ==0){
				pushDynArr(stack, 2.7182818);

			}
			else if(strcmp(s, "pi") ==0){
				pushDynArr(stack, 3.14159265);

			}
			else{
				double num;
				if(isNumber(s, &num) == 1){
					pushDynArr(stack, num);
				}
				else{
					printf("INVALID NUMBER!: %s\n", s);
					exit(0);
				}
			}

		}
	}	//end for

	/* FIXME: You will write this part of the function (2 steps below)
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	popDynArr(stack);
	int stack_size = sizeDynArr(stack);
	if(stack_size !=0){


		for(i=0;i<stack_size;++i){
			printf("The value left is: %1f", getDynArr(stack, i));
		}
		deleteDynArr(stack);
		exit(0);
	}
	printf("RESULT: %1f\n", result);
	deleteDynArr(stack); //deallocate
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc <= 1){
		printf("Only one or less argument\n");
		return 0;
	}

	calculate(argc,argv);
	return 0;
}
