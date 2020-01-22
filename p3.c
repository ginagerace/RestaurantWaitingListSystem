//FILE NAME: "p3.c"

#include "program4.h"

//initialize the stack
void init(Stack* s) {
  s->head = NULL;
  s->TOTAL = 0;
}


//resetting the stack so it can be used again
void clear(Stack* s) {
  Node *p = s->head;
  Node *pnext;
  while(p != NULL) {
    pnext = p->next;
    free(p);
    p = pnext;
  }
  init(s);
}


// add a new node to the end of the linked list; used for a & c commands
void addToList(Stack *s, char *n, int si, boolean in){
  //create new group node
  Node *temp = (Node*) malloc (sizeof(Node));
  temp->name = n;
  temp->size = si;
  temp->inRest = in;
  temp->next = NULL;
  //add node to list
  if(s->head == NULL)               //if list is empty
    s->head = temp;
  else if(s->head->next == NULL)    //if there is only one item in list
    s->head->next = temp;
  else{                             //insert at end of list
    Node *current = s->head;
    while(current->next != NULL)
      current = current->next;
    current->next = temp;
  }
  s->TOTAL = s->TOTAL + 1;
}


//indicates whether a name already exists; used for a, c, w, & l commands
boolean doesNameExist(Stack *s, char *name){
  //check if list is empty
  if(s->head == NULL)
    return FALSE;
  if(DebugMode == TRUE)
        printf("\nDebug Mode: traversing through list...\n");
  Node *temp = s->head;         //create a temporary node
  while(temp != NULL){
    if(DebugMode == TRUE) {
        printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
        if(temp->inRest == YES)   printf("Yes\n");
        else    printf("No\n");
    }
    //check if names are the same
    if(strcmp(temp->name, name) == 0)
      return TRUE;
    temp = temp->next;
  }
  free(temp);
  return FALSE;
}


//change in-restaurant status; used for w command
//returns returns FALSE if group already marked as present
boolean updateStatus(Stack *s, char *name) {
  Node *temp = s->head;         //create a temporary node
  if(DebugMode == TRUE)
        printf("\nDebug Mode: traversing through list...\n");
  //get to correct node
  while(strcmp(temp->name, name) != 0){
    if(DebugMode == TRUE) {
        printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
        if(temp->inRest == YES)   printf("Yes\n");
        else    printf("No\n");
    }
    temp = temp->next;
  }
  //check if group has already been marked present
  if(temp->inRest == YES)
    return FALSE;
  //mark group present
  else {
    temp->inRest = YES;
    return TRUE;
  }
}


//find the first in-restaurant group that can fit at a given table; used for r command
//returns name of group; group should be removed from list
char *retrieveAndRemove(Stack *s, int x, int *done){
  Node *temp = s->head;         //create a temporary node
  char *hold;
  if(DebugMode == TRUE)
        printf("\nDebug Mode: traversing through list...\n");
  //if group is first on list
  if(temp!=NULL && temp->size <= x){
      hold = temp->name;
      s->head = temp->next;
      if(DebugMode == TRUE) {
            printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
            if(temp->inRest == YES)   printf("Yes\n");
            else    printf("No\n");
        }
      s->TOTAL = s->TOTAL - 1;
      *done = TRUE;
  }
  else {
      Node *p = (Node*) malloc(sizeof(Node));
      while(temp->next != NULL){
        if(DebugMode == TRUE) {
            printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
            if(temp->inRest == YES)   printf("Yes\n");
            else    printf("No\n");
        }
        //check group size and if they are in the restaurant
        if(temp->next->size <= x && temp->next->inRest==YES){
          hold = temp->next->name;
          temp->next = temp->next->next;
          s->TOTAL = s->TOTAL - 1;
          *done = TRUE;
          break;
        }
        temp = temp->next;
      }
  }
  return hold;
}


//return the number of groups waiting ahead of a specific group; used for l command
int countGroupsAhead(Stack *s, char *name){
  Node *temp = s->head;     //create a temporary node
  int count = 0;            //create a counter
  if(DebugMode == TRUE)
        printf("\nDebug Mode: traversing through list...\n");
  while(strcmp(temp->name, name) != 0){
    if(DebugMode == TRUE) {
        printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
        if(temp->inRest == YES)   printf("Yes\n");
        else    printf("No\n");
    }
    //increase count and continue through list
    count++;
    temp = temp->next;
  }
  return count;
}


//traverse down list until a specific name is found & print out each node's size; used for l command
void displayGroupSizeAhead(Stack *s, char *name){
  Node *temp = s->head;         //create a temporary node
  printf("\nThe group sizes are: ");
  if(DebugMode == TRUE)
        printf("\nDebug Mode: traversing through list...\n");
  //check each name to see if you have reached the given name
  while(strcmp(temp->name, name) != 0){
    if(DebugMode == TRUE) {
        printf("Group Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
        if(temp->inRest == YES)   printf("Yes\n");
        else    printf("No\n");
    }
    printf("%d ", temp->size);
    temp = temp->next;
  }
  printf("\n");
}


//traverse entire list & print out each node's info; used for d command
void displayListInformation(Stack *s){
  Node *temp = s->head;         //create a temporary node
  //iterate through list and print out info
  while(temp != NULL){
    printf("\nGroup Name: %s    Size: %d    In Restaurant: ", temp->name, temp->size);
    if(temp->inRest == YES)
        printf("Yes");
    else
        printf("No");
    temp = temp->next;
  }
}
