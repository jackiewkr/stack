/*
Test program for imple stack implementation in C

By Jackie W.
24 dec 21
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "datastructures.h"

int main() {
  //create stack
  struct stack temp;
  initStack(&temp, 5);
  bool loop = true;
  while (loop) {
    char ch[64];
    int num;
    printf("> ");
    fgets(ch,64,stdin);
    ch[strlen(ch)-1] = '\0';//gets rid of any leading chars like \n
    if (strcmp(ch,"push")==0){
      //push
      printf("Num: ");
      scanf("%i",&num);
      pushStack(&temp, num);
    } else if (strcmp(ch,"pop")==0) {
      //pop
      num = popStack(&temp);
      printf("Popped %i\n",num);
    } else if (strcmp(ch,"peek")==0) {
      //peek
      num = peekStack(&temp);
      printf("Peeked %i\n",num);
    } else if (strcmp(ch,"discard")==0) {
      //discard
      loop = false;
      }
  }

  //frees stack
  discardStack(&temp);
  return 0;
}
