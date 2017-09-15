#pragma once
#include "HabilidadEspecial.h"

class DeshacerDano : public HabilidadEspecial{
public:
  DeshacerDano();
  void aplicar(Luchador*);
};
