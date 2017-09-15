#pragma once
#include "HabilidadEspecial.h"
#include <thread>

class Invulnerabilidad : public HabilidadEspecial{
public:
  Invulnerabilidad();
  void aplicar(Luchador*);
  void monitorearTurnos(int, Luchador*);
};
