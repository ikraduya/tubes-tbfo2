#include "parser.h"
#include "boolean.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* *** Input / Output *** */
float HitungHasilTree(Tree P)
{
  int i;
  float Hasil;

  if (!IsTreeEmpty(P)) {
    if (AkarOp(P) == '#' )
      Hasil = AkarBil(P);
    else if(AkarOp(P) == '+')
      Hasil = HitungHasilTree(Left(P)) + HitungHasilTree(Right(P));
    else if(AkarOp(P) == '-')
      Hasil = HitungHasilTree(Left(P)) - HitungHasilTree(Right(P));
    else if(AkarOp(P) == '*')
      Hasil = HitungHasilTree(Left(P)) * HitungHasilTree(Right(P));
    else if(AkarOp(P) == '/')
      Hasil = HitungHasilTree(Left(P)) / HitungHasilTree(Right(P));
    else if(AkarOp(P) == '^')
      Hasil = powf(HitungHasilTree(Left(P)),HitungHasilTree(Right(P)));
    else if(AkarOp(P) == '(')
      Hasil = HitungHasilTree(Right(P));  
  }
  return Hasil;
}
