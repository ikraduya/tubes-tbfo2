#include "tree.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Konstruktor *** */

/* Manajemen Memory */
addrTNode AlokNode (infotypeOp op, infotypeBil bil);
/* Mengirimkan addrTNode hasil alokasi sebuah elemen op atau bil */
/* Jika alokasi berhasil, maka addrTNode tidak Nil, dan misalnya menghasilkan P,
  maka AkarOp(P) = '', AkarBil(P)=X, Parent(P)=Nil, Left(P)=Nil, dan Right(P)=Nil  */
/* Jika alokasi gagal, mengirimkan Nil */
{
  addrTNode P;
  P = (addrTNode) malloc(sizeof(TNode));
  if (P != Nil){
    AkarOp(P) = op;
    AkarBil(P) = bil;
    Left(P) = Nil;
    Right(P) = Nil;
    Parent(P) = Nil;
  }
  return P;
}
void DealokNode (addrTNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrTNode P */
{
  free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (Tree P)
/* Mengirimkan true jika P adalah pohon parsing binary kosong */
{
  return (P == Nil);
}

boolean IsOneElmt (Tree P)
/* Mengirimkan true jika P adalah pohon parsing binary dengan satu elemen */
{
  return (P != Nil && Left(P) == Nil && Right(P) == Nil && Parent(P) == Nil);
}


/* *** Input / Output *** */
void PrintTree(Tree P, int indent)
/* I.S. P mungkin kosong */
/* Mencetak tree ke layar */
{
  int i;

  if (!IsTreeEmpty(P)) {
    if (Akar(P) != Nil) {
      for (i=0; i<indent; i++) {
        printf("-");
      }
      if (AkarOp(P) == )
      printf("%s\n", Akar(P));
      if (Left(P) != Nil) {
        PrintTree(Left(P), indent+1);
      }
      if (Right(P) != Nil) {
        PrintTree(Right(P), indent+1);
      }
    }
    
  }
}
