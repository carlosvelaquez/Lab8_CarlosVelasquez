#include "HabilidadPasiva.h"

void HabilidadPasiva::aplicar(Luchador* luchador, int exp){
  luchador->setExp(luchador->getExp() + exp);
}
