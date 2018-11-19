#include <stdio.h>
#include "boolean.h"
#include "stacktreeptr.h"
#include "tree.h"

#define Nil NULL

void DecimalCase (char *inp,int *count, int idx);
/*Menangani kasus inputan desimal*/
/*I.S. inp terdefinisi, count = 0, idx adalah indeks koma (,)*/
/*F.S count menjadi jumlah angka dibelakang koma, inp menjadi string angka dibelakang koma*/

void MinusCase (char *inp);
/*Menangani kasus inputan minus*/
/*I.S. inp terdefinisi*/
/*F.S. inp menjadi inputan tanpa minus*/

float KarakterToFloat (char *inp);
/*Mengembalikkan nilai float dari sebuah array of char inp*/

int compare(char node, char elmt);
/*Mengirimkan hasil perbandingan operator berdasarkan level prioritas*/
/* 1 jika node lebih prioritas dripda elmt, 0 jika sama, -1 jika kurang prioritas*/

void BuildTree(Tree TTemp, Tree T,Tree TPrev, StackTreePtr *S);
/*I.S. TTemp, T,TPrev , S terdefinisi*/
/*F.S. T dimasukkan TTemp sesuai dengan aturan*/

void GetElment(char *inp,char *elmtChar, float *elmtAngka,int *idx,Tree TTemp);
/*I.S. inp, idx terdefinisi*/
/*F.S mengambil Element dan disimpan di elmtChar dan elmtAngka*/
/*jika Angka maka elmtAngka berisi angka dan elmtChar berisi #*/
/*jika operator maka elmtChar beriis operator dan elmtAngka berisi 0*/

void GrowTREE(char *inp, Tree *T);
/*I.S. inp terdefinisi, T sembarang*/
/*F.S. T menjadi Tree yang diinginkan*/
