/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2*(*a);
    printf("%d\n",*a);
    /*Set b to half its original value*/
    *b = (*b)/2;
    printf("%d\n",*b);
    /*Assign a+b to c*/
    c = *a + *b;
    printf("%d\n", c);
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x =7;
    int* i = &x;
    int y =8;
    int* j = &y;
    int z =9;
    /*Print the values of x, y and z*/
    printf("x,y,z: %d %d %d\n", x,y,z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int c;
    c=foo(i,j,z);
    /*Print the value returned by foo*/
    printf("return value: %d\n", c);
    /*Print the values of x, y and z again*/
    printf("x,y,z: %d %d %d\n", x,y,z);
    /*Is the return value different than the value of z?  Why?*/
    // Yes because z is not a pointer and we didn't pass a pointer in for z.
    return 0;
}
