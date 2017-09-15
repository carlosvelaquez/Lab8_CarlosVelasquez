#pragma once
#include "HabilidadPasiva.h"

class DobleExp : public HabilidadPasiva{
public:
  DobleExp(int);
  void aplicar(Luchador*, int);
};
