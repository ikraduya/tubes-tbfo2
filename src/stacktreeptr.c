#include "stacktreeptr.h"

void CreateEmpty (StackTreePtr *S){
  Top(*S) = NilStack;
  InfoTop(*S) = NilElmtS;
}

boolean IsEmpty (StackTreePtr S){
  return (Top(S) == NilStack);
}

boolean IsFull (StackTreePtr S){
  return (Top(S) == MaxEl);
}

void Push (StackTreePtr * S, infotypeStackTreePtr X){
  Top(*S)++;
  InfoTop(*S) = X;
}

void Pop (StackTreePtr * S, infotypeStackTreePtr* X){
  *X = InfoTop(*S);
  Top(*S)--;
}
