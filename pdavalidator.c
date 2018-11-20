#include "pdavalidator.h"
#include <stdio.h>

/* Realisasi Fungsi */
int findTransitionTableIdx(int state, char sym, Stack S)
/* Jika simbol diterima PDA fungsi akan mengembalikan index pada transition table */
{
  int i, idx;
  boolean found = false;
  for (i=0; i<deltaCount; i++) {
    if ((state == State(D[i])) && (Input(D[i]) == sym) && (TopStack(D[i]) == InfoTopS(S))) {
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


float strToFloat(char *s)
/* Mengubah string menjadi float */
{
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

boolean IsExprValid(char *s)
/* Memeriksa apakah ekspresi valid */
{
  Stack S;
  boolean valid = false,
          stuck = false;
  int currentQ = 0;
  CreateEmptyS(&S);

  PushS(&S, 'Z');
  while (*s) {
    if (*s != '\n' && !stuck) {
      transition(&currentQ, *s, &S, &stuck);
    }
    s++;
  }
  if (stuck || currentQ != 2) {
    if (currentQ != 2) {
      if (currentQ == 4 && InfoTopS(S) == 'Y') {
        return true;
      }
    }

    return false;
  } else {  // currentQ == 2
    return true;
  }
}

void transition(int *state, char sym, Stack *S, boolean * stuck)
/* transisi state dan merubah stack sesuai dengan tabel transisi */
{
  int idx;
  char popped;

  idx = findTransitionTableIdx(*state, sym, *S);
  if (idx == -999) {
    *stuck = true;
  } else {
    // printf("%s %s %s %s %s\n",
    //       D[idx].state, D[idx].inp, D[idx].topStack, CStack(D[idx]), CState(D[idx]));
    *state = CState(D[idx])[1] - '0';
    if (strcmp(CStack(D[idx]), "XZ") == 0 || strcmp(CStack(D[idx]), "XX") == 0) {  // PushS X to stack
      PushS(S, 'X');
    } else if (strcmp(CStack(D[idx]), "YZ") == 0 || strcmp(CStack(D[idx]), "YX") == 0) { // PushS Y to stack
      PushS(S, 'Y');
    } else if (strcmp(CStack(D[idx]), "E") == 0) {  // Pop Stack
      PopS(S, &popped);
    } else if (strcmp(CStack(D[idx]), "X") == 0 || strcmp(CStack(D[idx]), "Z") == 0) {
      // do nothing
    }
  }
}
