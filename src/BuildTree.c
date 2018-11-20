#include <stdio.h>
#include <string.h>
#include <math.h>
#include "BuildTree.h"
void DecimalCase (char *inp,int *count, int idx)
/*Menangani kasus inputan desimal*/
/*I.S. inp terdefinisi, count = 0, idx adalah indeks koma (,)*/
/*F.S count menjadi jumlah angka dibelakang koma, inp menjadi string angka dibelakang koma*/
{
  char temp[10] = {0};
  int idxB = 0, i;
  for (i = idx+1; i <= strlen(inp)-1;i++){
    temp[idxB] = inp[i];
    idxB++;
  }
  *count = strlen(temp);
  strcpy(inp,temp);
}

void MinusCase (char *inp)
/*Menangani kasus inputan minus*/
/*I.S. inp terdefinisi*/
/*F.S. inp menjadi inputan tanpa minus*/
{
  char temp[10] = {0};
  int idx = 0, i;
  for (i = 1; i <= strlen(inp)-1;i++){
    temp[idx] = inp[i];
    idx++;
  }
  strcpy(inp,temp);
}

float KarakterToFloat (char *inp)
/*Mengembalikkan nilai float dari sebuah array of char inp*/
{
  int decCount;
  int decHeadCounter = 0;
  int length, i;
  boolean isDec = false;
  length = strlen(inp);
  float hasil = 0.0;
  for (i = 0; i <= length-1;i++){
    if (inp[i] == '.'){
      isDec = true;
      break;
    }else{
      hasil *= 10;
      hasil += inp[i] - 48;
      decHeadCounter++;
    }
  }
  if (inp[0] == '-'){
    MinusCase(inp);
    return KarakterToFloat(inp) * -1;
  }
  else if (isDec){
    DecimalCase(inp, &decCount,decHeadCounter);
    return hasil + KarakterToFloat(inp) / pow(10,decCount);
  }
  return hasil;
}

int compare(char node, char elmt)
/*Mengirimkan hasil perbandingan operator berdasarkan level prioritas*/
/* 1 jika node lebih prioritas dripda elmt, 0 jika sama, -1 jika kurang prioritas*/
{
  int inode,ielmt;
  switch (node){
    case '@':{
      inode = 0;
      break;
    }
    case '+':{
      inode = 1;
      break;
    }
    case '-':{
      inode = 1;
      break;
    }
    case '*':{
      inode = 2;
      break;
    }
    case '/':{
      inode = 2;
      break;
    }
    case '^':{
      inode = 3;
      break;
    }
    case '(':{
      inode = 4;
      break;
    }
    case '#':{
      inode = 5;
      break;
    }
  }
  switch (elmt){
    case '@':{
      ielmt = 0;
      break;
    }
    case '+':{
      ielmt = 1;
      break;
    }
    case '-':{
      ielmt = 1;
      break;
    }
    case '*':{
      ielmt = 2;
      break;
    }
    case '/':{
      ielmt = 2;
      break;
    }
    case '^':{
      ielmt = 3;
      break;
    }
    case '(':{
      ielmt = 4;
      break;
    }
    case '#':{
      ielmt = 5;
      break;
    }
  }
  if (inode > ielmt)
    return 1;
  else if (inode < ielmt)
    return -1;
  else
    return 0;
}

void BuildTree(Tree TTemp, Tree T,Tree TPrev, StackTreePtr *S)
/*I.S. TTemp, T,TPrev , S terdefinisi*/
/*F.S. T dimasukkan TTemp sesuai dengan aturan*/
{
  infotypeStackTreePtr infoS;
  if (IsTreeEmpty(T)) {
    Push(S,TTemp);
  }
  else if ((compare(AkarOp(T),AkarOp(TTemp)) >= 0) && ((AkarOp(T) != '^') || (AkarOp(TTemp) != '^'))){
    Left(TTemp) = T;
    if (IsTreeEmpty(TPrev)){
      Pop(S,&infoS);
      Push(S,TTemp);
    }else
      Right(TPrev) = TTemp;
  }
  else if (IsOneElmt(T))
    Right(T) = TTemp;
  else{
    TPrev = T;
    T = Right(T);
    BuildTree(TTemp,T,TPrev,S);
  }
}

void GetElment(char *inp,char *elmtChar, float *elmtAngka,int *idx,Tree TTemp)
/*I.S. inp, idx terdefinisi*/
/*F.S mengambil Element dan disimpan di elmtChar dan elmtAngka*/
/*jika Angka maka elmtAngka berisi angka dan elmtChar berisi #*/
/*jika operator maka elmtChar beriis operator dan elmtAngka berisi 0*/
{
  char elmt[10] = {0};
  int idxe = 0;
  int length = strlen(inp);
  *elmtAngka = 0.0;
  *elmtChar = inp[*idx];
  if (((inp[*idx] >= 48) && (inp[*idx] <= 57)) || ( (IsTreeEmpty(TTemp) || ((AkarOp(TTemp) != '#') && (AkarOp(TTemp) != ')'))) && (inp[*idx] == '-') ) ) {
    elmt[idxe] = *elmtChar;
    *idx+=1;
    idxe++;
    while (((*idx <= length-1) && (inp[*idx] >= 48) && (inp[*idx] <= 57)) || (inp[*idx] == 46)) {
      elmt[idxe] = inp[*idx];
      *idx+=1;
      idxe++;
    }
    *elmtAngka = KarakterToFloat(elmt);
    *elmtChar = '#';
  }else
    *idx+=1;
}

void GrowTREE(char *inp, Tree *T)
/*I.S. inp terdefinisi, T sembarang*/
/*F.S. T menjadi Tree yang diinginkan*/
{

  StackTreePtr S;
  char elmtChar;
  int idx,length;
  float elmtAngka;
  Tree TTemp = Nil;
  Tree TTemp2;
  Tree TPrev = Nil;
  CreateEmpty(&S);
  idx = 0;
  length = strlen(inp);
  while (idx <= length-1){
    GetElment(inp,&elmtChar,&elmtAngka,&idx,TTemp);
    TTemp = AlokNode(elmtChar,elmtAngka);
    if (AkarOp(TTemp) == ')'){
      Pop(&S,&TTemp2);
      AkarOp(TTemp2) = '(';
    }else{
      *T = InfoTop(S);
      TPrev = Nil;
      BuildTree(TTemp,*T,TPrev,&S);
    }
    if (AkarOp(TTemp) == '('){
      AkarOp(TTemp) = '@';
      Push(&S,TTemp);
    }
  }
  *T = InfoTop(S);
}
