#ifndef TREE_H
#define TREE_H

/* Modul lain yang digunakan : */
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

#define Nil NULL

typedef float infotypeBil;
typedef char infotypeOp;

/* *** Definisi Type Pohon *** */
typedef struct tNode *addrTNode;
typedef struct tNode {
  infotypeOp infoOp;
	infotypeBil infoBil;
	addrTNode left;
	addrTNode right;
  addrTNode parent;
} TNode;

extern addrTNode lastInsertedNode;
extern addrTNode currentRoot;

/* Definisi Pohon Parsing Binary : */
/* Pohon kosong : P = Nil */
typedef addrTNode Tree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define AkarOp(P) (P)->infoOp
#define AkarBil(P) (P)->infoBil
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Parent(P) (P)->parent

/* *** Konstruktor *** */
/* Manajemen Memory */
addrTNode AlokNode (infotypeOp op, infotypeBil bil);
/* Mengirimkan addrTNode hasil alokasi sebuah elemen op atau bil */
/* Jika alokasi berhasil, maka addrTNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Sibling(P)=Nil, dan Child(P)=Nil  */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrTNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrTNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (Tree P);
/* Mengirimkan true jika P adalah pohon binary kosong */

boolean IsOneElmt (Tree P);
/* Mengirimkan true jika P adalah pohon dengan satu elemen */

/* *** Input / Output *** */
void PrintTree(Tree P, int indent);
/* I.S. P mungkin kosong */
/* Mencetak tree ke layar */

#endif
