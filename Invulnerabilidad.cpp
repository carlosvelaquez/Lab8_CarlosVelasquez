#include "Invulnerabilidad.h"

Invulnerabilidad::Invulnerabilidad(){
  deltaDefensaMagica = 1;
  deltaDefensaFisica = 1;
}

void Invulnerabilidad::aplicar(Luchador* luchador){
  int turnos = luchador->getTurnos();

  luchador->setDefensaMagica(luchador->getDefensaMagica() + deltaDefensaMagica);
  luchador->setDefensaFisica(luchador->getDefensaFisica() + deltaDefensaFisica);

  thread monitorTurnos(&Invulnerabilidad::monitorearTurnos, this, turnos, luchador);
  monitorTurnos.detach();
}

void Invulnerabilidad::monitorearTurnos(int turnos, Luchador* luchador){
  while (luchador->getTurnos() != turnos+1) {
    this_thread::sleep_for(chrono::milliseconds(1000));
  }

  luchador->setDefensaMagica(luchador->getDefensaMagica() - deltaDefensaMagica);
  luchador->setDefensaFisica(luchador->getDefensaFisica() - deltaDefensaFisica);

  std::cout << "La habilidad especial de "<< luchador.getNombre() << " dejó de hacer efecto." << '\n';
}
