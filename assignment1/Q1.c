/* CS261- Assignment 1 - Q.1*/
/* Name: Julian Weisbord
 * Date: 09/30/15
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *studentArray = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return studentArray;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
		 int i,j, possibleID;
		 time_t timeVal;
		 srand((unsigned) time(&timeVal));

		//  ids must be unique, why do some become 0?
		int check = 0;
		int one =1;
		for(i=0; i< 10; ++i){
			while(one >0){
				possibleID = (rand() % 10);
				for(j=0; j< 10; ++j){
				 	if(students[j].id ==possibleID){
						check =1;
						one =0; //to break out of while
						break; //break out of for
				 	}
			 	}
				if(check ==0){
					break;
				}

			} //while
			one = 1;
			if(check ==0){
			 	students[i].id = possibleID;
			}
			 	students[i].score = (rand() % 100);
		}
}

void output(struct student* students){
		int i;
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

		for(i=0; i < 10; ++i){
			printf("ID%d Score%d\n", students[i].id, students[i].score);
		}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
		stud = allocate();
    /*call generate*/
		generate(stud);
    /*call output*/
		output(stud);
    /*call summary*/

    /*call deallocate*/

    return 0;
}
