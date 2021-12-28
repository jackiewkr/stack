#ifndef DATASTRUCTURES_H_/*Guard against double inclusion*/
#define DATASTRUCTURES_H_

struct stack {
  int size;
  int tos; //top of stack index
  int * arr; //pointer to array 
};

void initStack(struct stack* s, int size);

int isStackEmpty(struct stack * s);

int isStackFull(struct stack * s);

void pushStack(struct stack * s, int item);

int popStack(struct stack * s);

int peekStack(struct stack * s);

void discardStack(struct stack * s);



#endif
