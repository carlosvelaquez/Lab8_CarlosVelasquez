#pragma once
#include "Luchador.h"

struct nodo{
  Luchador* datos;
  nodo* next;
};

class Lista{
private:
  nodo* cabeza;
  nodo* cola;

public:
  Lista();
  void anadir(Luchador*);
  void eliminarNodo(int);
  Luchador* at(int);
  int size();

  Luchador* operator[] (int indice){
    return at(indice);
  }
};
