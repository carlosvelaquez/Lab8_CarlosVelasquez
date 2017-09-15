#pragma once
#include "Luchador.h"

class HabilidadPasiva{
protected:
  int multiplicadorExp;
public:
  virtual void aplicar(Luchador*, int);
};
