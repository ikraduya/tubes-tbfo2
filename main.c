#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "stackt.h"
#include "pdavalidator.h"

Delta D[deltaCount+1];
int i;  // iterator

/* Deklarasi Function */
int findTransitionTableIdx(int state, char sym, Stack S);
float strToFloat(char *s);
boolean IsExprValid(char *s);

int main() {
  char str[1000];

  FILE *deltaPtr;
  deltaPtr = fopen("delta.txt", "r");
  for (i=0; i<deltaCount; i++){
      fscanf(deltaPtr,
          "%s %s %s %s %s", 
          D[i].state, D[i].inp, D[i].topStack, CStack(D[i]), CState(D[i])
      );
  }
  fclose(deltaPtr);

  fgets(str,1000,stdin);
  if (IsExprValid(str)) {
    printf("valid\n");
  } else {
    printf("not valid\n");
  }

  return 0;
}
