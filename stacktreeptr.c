#include "stacktreeptr.h"

void CreateEmpty (StackTreePtr *S){
  Top(*S) = Nil;
  InfoTop(*S) = Nil;
}

boolean IsEmpty (StackTreePtr S){
  return (Top(S) == Nil);
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
