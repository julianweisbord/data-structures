#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"
#include "dynamicArray.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  // DynArr* mainList = createDynArr(10);
  FILE * filePtr;
  char filename[50], *nullPtr;
  int prior;
  DynArr * list = createDynArr(10);
  char filey[256];
  TYPE min;

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');
      //different cases
      switch(cmd){
        case 'l':
          printf("Loading todo list!\n");

          filePtr = fopen("todo.txt", "r");

          loadList(list, filePtr);
          fclose(filePtr);
          printf("done...");
          break;

        case 's':
	  if(sizeDynArr(list)>0){

  	 filePtr = fopen("todo.txt", "w");
  	 if(filePtr==NULL){
  	 	fprintf(stderr, "Can't OPen file");
  		break;
  	 }
  	 saveList(list, filePtr);
  	 fclose(filePtr);

  	 printf("saved.\n\n");
	 }
	  else
		  printf("Empty todo list.");

    break;


        case 'a':


          printf("Enter the task description: \n");
          fgets(filey, sizeof(filey), stdin);
          printf("What is the priority, bro?\n");
          scanf("%d",&prior);
          fgetc(stdin);
          TaskP theTask;
          theTask = createTask(prior,filey);
          addHeap(list, theTask, compare);

          break;
        case 'g':

        min = getMinHeap(list);
        printf("Printing the root.\n");
        print_type(min);
        break;

        case 'r':
          printf("Removing...\n");
          removeMinHeap(list, compare);
          break;
        case 'p':
          printf("Printing the list: \n");
          printList(list);
          break;
        case 'e':
          printf("Exitting...");
          exit(0);
      }

      /* Fixme:  Your logic goes here! */

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(list);

  return 0;
}
