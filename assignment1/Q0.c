/* CS261- Assignment 1 - Q. 0*/
/* Name: Julian Weisbord
 * Date: 09/26/15
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    printf("value pointed by iptr: %d\n", *iptr);
     /*Print the value pointed to by iptr*/
    printf("address pointed by iptr: %p\n", iptr);
     /*Print the address pointed to by iptr*/
    printf("address of iptr: %p\n",&iptr);
     /*Print the address of iptr itself*/
}

int main(){
    int x =1;
    /*declare an integer x*/
    printf("Address of x: %p\n", &x);
    /*print the address of x*/
    fooA(&x);
    /*Call fooA() with the address of x*/
    printf("value of x%d\n", x);
    /*print the value of x*/

    return 0;
}
