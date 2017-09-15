#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Luchador{
protected:
  string nombre;
  int batallasGanadas;
  int clasesAprendidas;
  vector<string> clases;

  int exp;
  int expEntregada;

  int hp;
  int ataqueMagico;
  int ataqueFisico;
  float defensaMagica;
  float defensaFisica;

  vector<HabilidadPasiva*> habilidadesPasivas;
  vector<HabilidadEspecial*> habilidadesEspeciales;

  int turnos;

public:
  string getNombre();
  int getBatallasGanadas();
  int getClasesAprendidas();
  vector<string> getClases();

  int getExp();
  int getExpEntregada();

  int getHP();
  int getAtaqueMagico();
  int getAtaqueFisico();
  float getDefensaMagica();
  float getDefensaFisica();

  void setNombre(string);
  void setBatallasGanadas(int);
  void setClasesAprendidas(int);
  void setClases(vector<string>);

  void setExp(int);
  void setExpEntregada(int);

  void setHP(int);
  void setAtaqueMagico(int);
  void setAtaqueFisico(int);
  void setDefensaMagica(float);
  void setDefensaFisica(float);

  int getTurnos();

  vector<HabilidadPasiva*> getHabilidadesPasivas();
  vector<HabilidadEspecial*> getHabilidadesEspeciales();

  friend ostream& operator<< (ostream& output, const Luchador& luch){
    output << luch.getNombre();
    return output;
  }

};
