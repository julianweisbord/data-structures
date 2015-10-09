/* CS261- Assignment 1 - Q.5*/
/* Name: Julian
 * Date: Weisbord
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    putchar(toupper(ch));
    printf("Char to upper: %1s\n", ch);
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    putchar(tolower(ch));
    printf("Char to lower: %1s\n", ch);
    return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
     int i;
    //  while(word[i] != NULL){
    //    ++i;
    //  }
}

int main(){
    /*Read word from the keyboard using scanf*/

    char arrays[100];
    char* word = arrays;
    printf("Enter a word.\n");
    scanf("%s", word);
    printf("%s\n", word);

    /*Call studly*/

    /*Print the new word*/

    return 0;
}
