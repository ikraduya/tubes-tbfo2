/* File: pdavalidator.h */
/* Definisi kumpulan fungsi pda validator */

#ifndef PDA_VALIDATOR_H
#define PDA_VALIDATOR_H

#include <string.h>
#include "stackt.h"
#include "boolean.h"

#define deltaCount 130

typedef struct {
  char state[3];
  char inp[2];
  char topStack[2];
  char cStack[3];
  char cState[3];
} Delta;

extern Delta D[deltaCount+1];

#define State(D)  (D).state[1]-'0'
#define Input(D)  (D).inp[0]
#define TopStack(D)  (D).topStack[0]
#define CStack(D)  (D).cStack
#define CState(D)  (D).cState

/* Deklarasi Fungsi */
int findTransitionTableIdx(int state, char sym, Stack S);
/* Jika simbol diterima PDA fungsi akan mengembalikan index pada transition table */

float strToFloat(char *s);
/* Mengubah string menjadi float */

boolean IsExprValid(char *s);
/* Memeriksa apakah ekspresi valid */

void transition(int *state, char sym, Stack *S, boolean * stuck);
/* transisi state dan merubah stack sesuai dengan tabel transisi */

#endif
