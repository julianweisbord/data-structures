/* CS261- Assignment 1 - Q.5*/
/* Name: Julian Weisbord
 * Date: 9/8/15
 * Solution description: Prints input string in studly caps
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
     int i =0;

     for(i; i < strlen(word); ++i){
        if(word[i] >=97 && word[i] <= 122){
      //  printf("word[i] %1s", word[i]);
          word[i] = toUpperCase(word[i]);
        }
     }
    i =1;
    for(i; i < strlen(word); i+=2){
      if(word[i] >=65 && word[i]<=91){
        word[i] =toLowerCase(word[i]);
      }
    }

}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[100];

    printf("Enter a word.\n");
    scanf("%s", word);
    // printf("%s\n", word);
    /*Call studly*/

    studly(word);
    /*Print the new word*/
      printf("word %s\n", word);

    return 0;
}
