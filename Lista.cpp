#include "Lista.h"

Lista::Lista(){
  cabeza = NULL;
  cola = NULL;
}

void Lista::anadir(Luchador* nLuchador){
  nodo* temp = new nodo;
  temp->datos = nLuchador;
  temp->next = NULL;

  if (cabeza == NULL) {
    cabeza = temp;
    cola = temp;
    temp = NULL;

  }else{
    cola->next = temp;
    cola = temp;
  }
}

void Lista::eliminarNodo(int indice){
  nodo* actual;
  nodo* anterior;

  actual = cabeza;

  for (int i = 1; i < indice; i++) {
    anterior = actual;
    actual = actual->next;
  }

  anterior->next = actual->next;
}

Luchador* Lista::at(int indice){
  int contador;
  nodo* temp = cabeza;

  if (indice > size() || indice < 1) {
    return NULL;
  }else{
    for (contador = 1; contador < indice; contador++) {
      temp = temp->next;
    }

    return temp->datos;
  }
}

int Lista::size(){
  bool fin = false;
  nodo* temp = cabeza;
  int contador = 0;

  if (cabeza != NULL) {
    contador++;
  }

  while (!fin && contador > 0) {
    if (temp->next != NULL) {
      contador++;
      temp = temp->next;
    }else{
      fin = true;
    }
  }

  return contador;
}
