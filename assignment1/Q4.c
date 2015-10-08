/* CS261- Assignment 1 - Q.4*/
/* Name: Julian Weisbord
 * Date: 9/7/15
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     /* Remember, each student must be matched with their original score after sorting */
		//  scores must be in ascending order
		int i,j, tempID, tempScore;
		 for(i=0; i < n; ++i){
 			for(j =0; j< n -i; ++j){
 				if(j >0){
 					if(students[j].score < students[j-1].score){
 						tempID = students[j].id;
 						tempScore =students[j].score;
 						students[j].id = students[j-1].id;
 						students[j].score = students[j-1].score;
 						students[j-1].id = tempID;
 						students[j-1].score = tempScore;
 					}
 				}
 			}
 		}
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n =10;
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    time_t timeVal;
    srand((unsigned) time(&timeVal));
    int i,j;
    for(i = 0; i < 10; ++i){
      students[i].id= (rand() % 10);
      students[i].score = (rand() % 101);
      for(j =0; j< i; ++j){
        if(students[i].id == students[j].id){
          students[i].id= (rand() % 10);
          j = -1;
        }
      }
    }

    /*Print the contents of the array of n students.*/
    for(i = 0; i< n; ++i){
      printf("id%d score%d\n",students[i].id,students[i].score);
    }
		printf("\n");
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
		for(i = 0; i< n; ++i){
      printf("id%d score%d\n",students[i].id,students[i].score);
    }
    return 0;
}
