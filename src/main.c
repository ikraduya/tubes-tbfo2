#include <stdio.h>
#include <string.h>
#include <math.h>
#include "boolean.h"
#include "stackt.h"
#include "pdavalidator.h"
#include "BuildTree.h"
#include "parser.h"

Delta D[deltaCount+1];
int i;  // iterator

/* Deklarasi Fungsi */
void greeting();

int main() {
  char str[1000], copiedStr[1000];
  Tree T = Nil;
  float hasil;
  boolean again;
  char lagi;

  FILE *deltaPtr;
  deltaPtr = fopen("delta.txt", "r");
  for (i=0; i<deltaCount; i++){
      fscanf(deltaPtr,
          "%s %s %s %s %s",
          D[i].state, D[i].inp, D[i].topStack, CStack(D[i]), CState(D[i])
      );
  }
  fclose(deltaPtr);

  greeting();
  again = true;
  // Program Loop
  while (again) {
    printf("\nMasukkan Ekspresi Matematika: ");
    scanf("%s",str);

    strcpy(copiedStr, str);
    if (IsExprValid(str)) {
      GrowTREE(copiedStr,&T);
      hasil = HitungHasilTree(T);
      if (isnormal(hasil)) {
        printf("Hasil: %.6f\n\n", hasil);
      } else {
        printf("MATH ERROR\n");
      }
    } else {
      printf("SYNTAX ERROR\n");
    }
    printf("Coba Lagi? (Y/n): ");
    scanf("\n%c", &lagi);
    if (lagi == 'n' || lagi == 'N') {
      again = false;
    } 
  }
  printf("bye :)\n");
  return 0;
}

void greeting() {
  printf(" _  __          _      _  ___    _ _            _______ ____  _____  \n");
  printf(" | |/ /    /\\   | |    | |/ / |  | | |        /\\|__   __/ __ \\|  __ \\ \n");
  printf(" | ' /    /  \\  | |    | ' /| |  | | |       /  \\  | | | |  | | |__) |\n");
  printf(" |  <    / /\\ \\ | |    |  < | |  | | |      / /\\ \\ | | | |  | |  _  / \n");
  printf(" | . \\  / ____ \\| |____| . \\| |__| | |____ / ____ \\| | | |__| | | \\ \\ \n");
  printf(" |_|\\_\\/_/    \\_\\______|_|\\_\\\\____/|______/_/    \\_\\_|  \\____/|_|  \\_\\\n");
  printf("\n");
  printf("Oleh: Azhar, Ikra, dan Nando\n");
}
