#include "Luchador.h"
#include "Aprendiz.h"
#include "Guerrero.h"
#include "Mago.h"
#include "DragonBorn.h"
#include "Lista.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  srand((int)time(0));

  Lista luchadores;
  vector<string> clases;

  /*luchadores.anadir(new DragonBorn(clases));
  (luchadores.at(1))->setNombre("TEST");
  string n = (luchadores.at(5))->getNombre();*/

  return 0;
}
