#include "DobleAtaque.h"

DobleAtaque::DobleAtaque(Luchador* luchador){
  nombre = "Doble Ataque";
  int r = rand();

  if (r%2 == 0) {
    deltaAtaqueFisico = luchador->getAtaqueFisico();
  }else{
    deltaAtaqueMagico = luchador->getAtaqueMagico();
  }
}

void DobleAtaque::aplicar(Luchador* luchador){
  int turnos = luchador->getTurnos();

  luchador->setAtaqueMagico(luchador->getAtaqueMagico() + deltaAtaqueMagico);
  luchador->setAtaqueFisico(luchador->getAtaqueFisico() + deltaAtaqueFisico);

  thread monitorTurnos(&DobleAtaque::monitorearTurnos, this, turnos, luchador);
  monitorTurnos.detach();

  usada = true;
}

void DobleAtaque::monitorearTurnos(int turnos, Luchador* luchador){
  while (luchador->getTurnos() != turnos+2) {
    this_thread::sleep_for(chrono::milliseconds(1000));
  }

  luchador->setAtaqueMagico(luchador->getAtaqueMagico() - deltaAtaqueMagico);
  luchador->setAtaqueFisico(luchador->getAtaqueFisico() - deltaAtaqueFisico);

  cout <<  endl << "La habilidad especial de "<< luchador->getNombre() << " dejó de hacer efecto." << endl;
}
