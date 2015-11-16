#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  FILE * filePtr;

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
          printf("Loading todo list!");
          if (fgets(filename, sizeof(filename), stdin) != NULL){//get rid of newline

    				nlptr = strchr(filename, '\n');
    				if (nlptr)
    					*nlptr = '\0';
			    }
          filePointer = fopen(filename, "r");
			    if (filePointer == NULL) {
		  		  fprintf(stderr, "error opening file %s\n", filename);
				    break;
			    }
          loadList(mainList, filePtr);
          fclose(filePtr);
          printf("done...");
          break;

        case 's':

        case 'a':
        case 'g':
        case 'r':
        case 'p':

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
  deleteDynArr(mainList);

  return 0;
}
