#include "DeshacerDano.h"

DeshacerDano::DeshacerDano(){
  nombre = "Deshacer Daño";
  deltaHP = 0;
}

void DeshacerDano::aplicar(Luchador* luchador){
  luchador->setHP(luchador->getHP() + luchador->getUltimoDano());
  usada = true;
}
