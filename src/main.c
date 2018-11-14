#include <stdio.h>
#include <string.h>
#include "../include/boolean.h"
#include "../include/stackt.h"

#define deltaCount 130

typedef struct {
  char state[3];
  char inp[2];
  char topStack[2];
  char cStack[3];
  char cState[3];
} Delta;

#define State(D)  (D).state[1]-'0'
#define Input(D)  (D).inp[0]
#define TopStack(D)  (D).topStack[0]
#define CStack(D)  (D).cStack
#define CState(D)  (D).cState

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

int findTransitionTableIdx(int state, char sym, Stack S) {
  int i, idx;
  boolean found = false;
  for (i=0; i<deltaCount; i++) {
    if ((state == State(D[i])) && (Input(D[i]) == sym) && (TopStack(D[i]) == InfoTop(S))) {
      idx = i;
      found = true;
      break;
    }
  }

  if (found) {
    return i;
  } else {
    return -999;
  }
}

void transition(int *state, char sym, Stack *S, boolean * stuck) {
  int idx;
  char popped;
  
  idx = findTransitionTableIdx(*state, sym, *S);
  if (idx == -999) {
    *stuck = true;
    printf("%d\n", idx);
  } else {
    printf("%s %s %s %s %s\n", 
          D[idx].state, D[idx].inp, D[idx].topStack, CStack(D[idx]), CState(D[idx]));
    *state = CState(D[idx])[1] - '0';
    if (strcmp(CStack(D[idx]), "XZ") == 0 || strcmp(CStack(D[idx]), "XX") == 0) {  // Push X to stack
      Push(S, 'X');
    } else if (strcmp(CStack(D[idx]), "E") == 0) {  // Pop Stack
      Pop(S, &popped);
    } else if (strcmp(CStack(D[idx]), "X") == 0 || strcmp(CStack(D[idx]), "Z") == 0) {
      // do nothing
    }
  }
}

boolean IsExprValid(char *s) {
  Stack S;
  boolean valid = false,
          stuck = false;
  int currentQ = 0;
  CreateEmpty(&S);

  Push(&S, 'Z');
  while (*s) {
    if (*s != '\n' && !stuck) {
      transition(&currentQ, *s, &S, &stuck);
    }
    s++;
  }
  if (stuck || currentQ != 2) {
    return false;
  } else {  // currentQ == 2
    return true;
  }
}

float strToFloat(char *s) {
  float result, decimalVal = 1;
  boolean negFlag, comma;
  int d;  // converted char to int

  if (*s == '-') {
    s++;
    negFlag = true;
  }

  comma = false;
  
  for (; *s; s++) {
    if (*s == '.') {
      comma = true;
    }
    d = *s - '0';
    if (d >= 0 && d <= 9) {
      if (comma) {
        decimalVal /= 10;
      }
      result = result * 10 + (float)d;
    }
  }
  return result * decimalVal;
}
