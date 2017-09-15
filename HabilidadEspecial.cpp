#include "HabilidadEspecial.h"

void HabilidadEspecial::aplicar(Luchador* luchador){
  luchador->setHP(luchador->getHP() + deltaHP);
  luchador->setAtaqueMagico(luchador->getAtaqueMagico() + deltaAtaqueMagico);
  luchador->setAtaqueFisico(luchador->getAtaqueFisico() + deltaAtaqueFisico);
  luchador->setDefensaMagica(luchador->getDefensaMagica() + deltaDefensaMagica);
  luchador->setDefensaFisica(luchador->getDefensaFisica() + deltaDefensaFisica);

  usada = true;
}
