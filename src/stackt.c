#include "stackt.h"

void CreateEmptyS (Stack *S){
    TopS(*S) = NilS;
    InfoTopS(*S) = NilS;
}

boolean IsEmptyS (Stack S){
    return (TopS(S) == NilS);
}

boolean IsFullS (Stack S){
    return (TopS(S) == MaxElS);
}

void PushS (Stack * S, infotypeS X){
    TopS(*S)++;
    InfoTopS(*S) = X;
}

void PopS (Stack * S, infotypeS* X){
    *X = InfoTopS(*S);
    TopS(*S)--;
}
