#include "Mago.h"

Mago::Mago(vector<string> nClases){
  clases = nClases;
  clasesAprendidas = clases.size();

  hp = 100;
  ataqueMagico = 15;
  ataqueFisico = 0;
  defensaMagica = .3;
  defensaFisica = 0;
  exp = 0;
  expEntregada = 75;

  bool aprendio = false;

  for (int i = 0; i < clasesAprendidas; i++) {
    if(clases[i] == "Mago"){
      aprendio = true;
    }
  }

  if (!aprendio) {
    clasesAprendidas++;
    clases.push_back("Mago");
    habilidadesEspeciales.push_back(new DeshacerDano());
  }
}
