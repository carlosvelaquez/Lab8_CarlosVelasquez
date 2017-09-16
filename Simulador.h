#pragma once
#include "Luchador.h"
#include "Aprendiz.h"
#include "Guerrero.h"
#include "Mago.h"
#include "DragonBorn.h"
#include "Alquimista.h"
#include "Lista.h"
#include <iostream>
#include <vector>

using namespace std;

class Simulador{
private:
  Lista* luchadores;

public:
  Simulador(Lista* nLista);
  void comenzar();
  int menu();
  void listarLuchadores();
};
