#include "Aprendiz.h"

Aprendiz::Aprendiz(vector<string> nClases){
  clases = nClases;
  clasesAprendidas = clases.size();

  hp = 60;
  ataqueMagico = 0;
  ataqueFisico = 10;
  defensaMagica = 0;
  defensaFisica = .1;
  exp = 0;
  expEntregada = 25;

  bool aprendio = false;

  for (int i = 0; i < clasesAprendidas; i++) {
    if(clases[i] == "Aprendiz"){
      aprendio = true;
    }
  }

  if (!aprendio) {
    clasesAprendidas++;
    clases.push_back("Aprendiz");
    habilidadesPasivas.push_back(new DobleExp());
  }
}
