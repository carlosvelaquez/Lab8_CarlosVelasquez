#include "DragonBorn.h"

DragonBorn::DragonBorn(vector<string> nClases){
  clases = nClases;
  clasesAprendidas = clases.size();

  hp = 200;
  ataqueMagico = 25;
  ataqueFisico = 23;
  defensaMagica = .2;
  defensaFisica = .2;
  exp = 0;
  expEntregada = 150;

  bool aprendio = false;

  for (int i = 0; i < clasesAprendidas; i++) {
    if(clases[i] == "DragonBorn"){
      aprendio = true;
    }
  }

  if (!aprendio) {
    clasesAprendidas++;
    clases.push_back("DragonBorn");
    habilidadesEspeciales.push_back(new DobleAtaqueMagico());
    habilidadesEspeciales.push_back(new DobleAtaqueFisico());
  }
}
