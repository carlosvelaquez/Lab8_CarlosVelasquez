#pragma once
#include <string>

using namespace std;

class Habilidad{
protected:
  string nombre;
public:
  string getNombre();
  void setNombre(string);
};
