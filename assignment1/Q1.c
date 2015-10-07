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
     struct student *students = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
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
	}

void output(struct student* students){
		int i,j, tempID, tempScore;
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
		//unordered
		for(i=0; i < 10; ++i){
			printf("ID%d Score%d\n", students[i].id, students[i].score);
		}
		printf("\n");
		// ordered
		int n = 10;
		for(i=0; i < n-1; ++i){
			for(j =0; j< n -i; ++j){
				if(students[j].id < students[j-1].id){
					tempID = students[j].id;
					tempScore =students[j].score;
					students[j].id = students[j-1].id;
					students[j].score = students[j-1].score;
					students[j-1].id = tempID;
					students[j-1].score = tempScore;

				}
			}
		}
		for(i=0; i < 10; ++i){
			printf("ID%d Score%d\n", students[i].id, students[i].score);
		}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
		 int i, largest, smallest;
		 largest = 0;
		 smallest = 0;
		//  compute largest
		 for(i = 0; i <10; ++i){
			 if(students[i].score > students[largest].score){
				 largest = i;
				 printf("Largest %d\n", largest);
			 }
		 }
		 printf("Largest %d\n", largest);
		 printf("Largest val %d\n", students[largest].score);
		 //compute smallest
		 for(i = 0; i < 10; ++i){
			 if(students[i].score < students[i-1].score){
				 smallest = i;
			 }
		 }
		 printf("smallest number: %d", students[smallest].score);

		//  compute average
		

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
		// if(stud != NULL){
 	// 		free(stud);
 	// 		stud = NULL;
		// }
		//  stud = NULL;
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
		summary(stud);
    /*call deallocate*/
		deallocate(stud);

    return 0;
}
