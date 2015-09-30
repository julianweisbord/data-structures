/* CS261- Assignment 1 - Q.3*/
/* Name: Julian Weisbord
 * Date: 09/28/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
  int i,j;
  int *temp = malloc(n *sizeof(int));
     /*Sort the given array number , of length n*/
  // for(i = 0; i< n; ++i){
  // //  temp[i] = number[i];
  //  number[i] = 0;
  //  printf("number[i]: %d", number[i]);
  // }
  for(j = 0; j <n; ++j){
    while(number[j] < number[j-1]){

      for(i = 0; i<n; ++i){
        if(i> 0){
          if(number[j] < number[j-1]){
            int x = number[j];
            number[j] = number[j-1];
            number[j-1] = x;
          }
        }
      }

    }

  }
    //  next sort temp array and store into number
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
    sort(my_array,n);

    /*Print the contents of the array.*/
    printf("Array: \n");
    for(i=0; i<20; ++i){
      printf("\t%d\n", my_array[i]);
    }
    return 0;
}
