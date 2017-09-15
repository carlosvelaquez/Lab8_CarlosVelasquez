#pragma once
#include "Luchador.h"

class HabilidadEspecial{
protected:
  bool usada = false;
  int deltaHP = 0;
  int deltaAtaqueFisico = 0;
  int deltaAtaqueMagico = 0;
  int deltaDefensaMagica = 0;
  int deltaDefensaFisica = 0;

public:
  virtual void aplicar(Luchador*);
};
