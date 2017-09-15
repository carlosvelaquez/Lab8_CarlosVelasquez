#pragma once
#include "HabilidadEspecial.h"
#include <cstdlib>
#include <thread>

class DobleAtaque : public HabilidadEspecial{
public:
  DobleAtaque(Luchador*);
  void aplicar(Luchador*);
  void monitorearTurnos(int, Luchador*);
};
