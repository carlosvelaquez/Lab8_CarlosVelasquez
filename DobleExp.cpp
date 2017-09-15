#include "DobleExp.h"

DobleExp::DobleExp(int nMult){
  multiplicadorExp = nMult;
}

void DobleExp::aplicar(Luchador* luchador, int exp){
  luchador->setExp(luchador->getExp() + exp);
}
