#pragma once
#include "Luchador.h"

class HabilidadPasiva : public Habilidad{
protected:
  int multiplicadorExp;
public:
  virtual void aplicar(Luchador*, int);
};
