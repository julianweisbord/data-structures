/* CS261- Assignment 1 - Q.3*/
/* Name: Julian Weisbord
 * Date: 09/28/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
}

int main(){

    /*Declare an integer n and assign it a value of 20.*/
    int n =20;
    int i;
    time_t timeVal;
    srand((unsigned) time(&timeVal));
    /*Allocate memory for an array of n integers using malloc.*/
    int *my_array = malloc(n * sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
    printf("Array: \n");
    for(i=0; i<20; ++i){
      my_array[i] = (rand() % n);
      /*Print the contents of the array.*/
      printf("\t%d\n", my_array[i]);
    }

    /*Pass this array along with n to the sort() function.*/

    /*Print the contents of the array.*/
    printf("Array: \n");
    for(i=0; i<20; ++i){
      printf("\t%d\n", my_array[i]);
    }
    return 0;
}
