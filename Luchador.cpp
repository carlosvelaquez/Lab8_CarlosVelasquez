#include "Luchador.h"

string Luchador::getNombre(){
  return nombre;
}

int Luchador::getBatallasGanadas(){
  return batallasGanadas;
}

int Luchador::getClasesAprendidas(){
  return clasesAprendidas;
}

vector<string> Luchador::getClases(){
  return clases;
}

int Luchador::getExp(){
  return exp;
}

int Luchador::getExpEntregada(){
  return expEntregada;
}

int Luchador::getHP(){
  return hp;
}

int Luchador::getAtaqueMagico(){
  return ataqueMagico;
}

int Luchador::getAtaqueFisico(){
  return ataqueFisico;
}

float Luchador::getDefensaMagica(){
  return defensaMagica;
}

float Luchador::getDefensaFisica(){
  return defensaFisica;
}

void Luchador::setNombre(string nNombre){
  nombre = nNombre;
}

void Luchador::setBatallasGanadas(int nBatallasGanadas){
  batallasGanadas = nBatallasGanadas;
}

void Luchador::setClasesAprendidas(int nClasesAprendidas){
  clasesAprendidas = nClasesAprendidas;
}

void Luchador::setClases(vector<string> nClases){
  clases = nClases;
}

void Luchador::setExp(int nExp){
  exp = nExp;
}

void Luchador::setExpEntregada(int nExpEntregada){
  expEntregada = nExpEntregada;
}

void Luchador::setHP(int nHP){
  hp = nHP;
}

void Luchador::setAtaqueMagico(int nAtaqueMagico){
  ataqueMagico = nAtaqueMagico;
}

void Luchador::setAtaqueFisico(int nAtaqueFisico){
  ataqueFisico = nAtaqueFisico;
}

void Luchador::setDefensaMagica(float nDefensaMagica){
  defensaMagica = nDefensaMagica;
}

void Luchador::setDefensaFisica(float nDefensaFisica){
  defensaFisica = nDefensaFisica;
}

vector<HabilidadPasiva*> Luchador::getHabilidadesPasivas(){
  return habilidadesPasivas;
}

vector<HabilidadEspecial*> Luchador::getHabilidadesEspeciales(){
  return habilidadesEspeciales;
}
