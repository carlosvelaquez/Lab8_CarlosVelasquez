#include "DeshacerDano.h"

DeshacerDano::DeshacerDano(){
  deltaHP = 0;
}

void DeshacerDano::aplicar(Luchador* luchador){
  luchador->setHP(luchador->getHP() + luchador->getUltimoDano());
  usada = true;
}
