#include "Guerrero.h"

Guerrero::Guerrero(vector<string> nClases){
  clases = nClases;
  clasesAprendidas = clases.size();

  hp = 120;
  ataqueMagico = 0;
  ataqueFisico = 15;
  defensaMagica = 0;
  defensaFisica = .3;
  exp = 0;
  expEntregada = 0;

  bool aprendio = false;

  for (int i = 0; i < clasesAprendidas; i++) {
    if(clases[i] == "Guerrero"){
      aprendio = true;
    }
  }

  if (!aprendio) {
    clasesAprendidas++;
    clases.push_back("Guerrero");
    habilidadesEspeciales.push_back(new Regeneracion());
  }
}
