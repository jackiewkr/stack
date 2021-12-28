#include <stdlib.h>
#include <stdio.h>
#include "datastructures.h"

/*STACK IMPLEMENTATION*/

void initStack(struct stack* s, int size) {
  /*Initialises a stack of size 'size'*/
  s->size = size;
  s->tos = 0;//has to always start at 0
  
  //allocates memory for an array of size 'size'
  s->arr = malloc(s->size * sizeof(int));

  //check if it failed
  if (s->arr == NULL) {
    //error
    printf("ERROR: Failed to malloc in initStack()\n");
  }
}

int isStackEmpty(struct stack * s) {
  if (s->tos == 0) {return 1;}
  return 0;
}

int isStackFull(struct stack * s) {
  if (s->tos == s->size) {return 1;}
  return 0;
}

void pushStack(struct stack * s, int item) {
  if (isStackFull(s)) {
    //stack is full, error
    printf("ERROR: Stack is full\n");
  } else {
    //stack isnt full

    //assign the index at tos to item
    s->arr[s->tos] = item;
    s->tos++;
  }
}

int popStack(struct stack * s) {
  if (isStackEmpty(s)) {
    //stack is empty, error
    printf("ERROR: Stack is empty\n");
    return NULL;
  } else {
    //stack isnt empty

    s->tos--;
    return s->arr[s->tos];
  }
}

int peekStack(struct stack * s) {
  if (!isStackEmpty(s)) {
    //stack isnt empty

    return s->arr[s->tos-1];
  }
}

void discardStack(struct stack * s) {
  /*Frees the allocated space for an array in the struct and resets some values*/
  free(s->arr);
  s->size = 0;
  s->tos = 0;
  
}
