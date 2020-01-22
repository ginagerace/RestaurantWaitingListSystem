//FILE NAME: "p2.c"

#include "program4.h"

void doAdd (Stack *s) {
 /* get group size from input */
 int size = getPosInt();
 if (size < 1) {
    printf ("Error: Add command requires an integer value of at least 1\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
 }

 /* get group name from input */
 char *name = getName();
 if (NULL == name) {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
 }

 printf ("Adding In-restaurant group \"%s\" of size %d\n", name, size);

 // add code to perform this operation here
 if(doesNameExist(s, name) == TRUE)
  printf("Sorry, that name is already taken.\n");
 else
  addToList(s, name, size, YES);
}


void doCallAhead (Stack *s) {
 /* get group size from input */
 int size = getPosInt();
 if (size < 1) {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
 }

 /* get group name from input */
 char *name = getName();
 if (NULL == name) {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
 }

 printf ("Adding Call-ahead group \"%s\" of size %d\n", name, size);

 // add code to perform this operation here
 if(doesNameExist(s, name) == TRUE)
  printf("Sorry, that name is already taken.\n");
 else
  addToList(s, name, size, NO);
}


void doWaiting (Stack *s) {
 /* get group name from input */
 char *name = getName();
 if (NULL == name) {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
 }

 printf ("Call-ahead group \"%s\" is now waiting in the restaurant\n", name);

 // add code to perform this operation here
 if(doesNameExist(s, name) == FALSE)
    printf("Sorry, that name does not exist.\n");
 else
    if(updateStatus(s, name) == FALSE)
        printf("That group has already been marked as present in the restaurant.\n");
}


void doRetrieve (Stack *s) {
 /* get table size from input */
 int size = getPosInt();
 if (size < 1) {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
 }
 clearToEoln();
 printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);

 // add code to perform this operation here
 if(s->head == NULL)
    printf("Waiting list is empty, no one to remove.\n");
 else{
    int done = FALSE;
    char *hold = retrieveAndRemove(s, size, &done);
    if(done == FALSE)
        printf("No one can be seated at this time.\n");
    else
        printf("%s has been removed from waiting list.\n", hold);
 }
}


void doList (Stack *s) {
 /* get group name from input */
 char *name = getName();
 if (NULL == name) {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
 }

 printf ("Group \"%s\" is behind the following groups\n", name);

 // add code to perform this operation here
 if(doesNameExist(s, name) == FALSE)
    printf("Sorry, that name does not exist.\n");
 else {
    printf("\nThere are %d groups ahead.", countGroupsAhead(s, name));
    displayGroupSizeAhead(s, name);
 }
}


void doDisplay (Stack *s) {
 clearToEoln();
 printf ("Display information about all groups\n");

 // add code to perform this operation here
 displayListInformation(s);
 printf("\nTotal Number of Groups: %d\n", s->TOTAL);

}
