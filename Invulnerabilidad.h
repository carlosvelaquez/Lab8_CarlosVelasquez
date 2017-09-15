#pragma once

class Invulnerabilidad : public HabilidadEspecial{
public:
  Invulnerabilidad();
  void aplicar(Luchador*);
  void monitorearTurnos(int, Luchador*);
};
