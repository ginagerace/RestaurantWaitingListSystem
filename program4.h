#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

int DebugMode;

typedef struct NodeStruct {
  char *name;
  int size;
  boolean inRest;
  struct NodeStruct *next;
} Node;

typedef struct StackStruct {
  Node *head;
  int TOTAL;
} Stack;

/* forward definition of functions */
void clearToEoln();
