#include "Alquimista.h"

Alquimista::Alquimista(vector<string> nClases){
  clases = nClases;
  clasesAprendidas = clases.size();

  hp = 130;
  ataqueMagico = 10;
  ataqueFisico = 10;
  defensaMagica = .2;
  defensaFisica = .2;
  exp = 0;
  expEntregada = 0;

  bool aprendio = false;

  for (int i = 0; i < clasesAprendidas; i++) {
    if(clases[i] == "Alquimista"){
      aprendio = true;
    }
  }

  if (!aprendio) {
    clasesAprendidas++;
    clases.push_back("Alquimista");
    habilidadesEspeciales.push_back(new Invulnerabilidad());
  }
}
