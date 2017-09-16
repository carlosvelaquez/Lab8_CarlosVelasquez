#include "Lista.h"

Lista::Lista(){
  cabeza = NULL;
  cola = NULL;
}

void Lista::anadir(Luchador* nLuchador){
  verificar();

  nodo* temp = new nodo;
  temp->datos = nLuchador;
  temp->next = NULL;

  if (cabeza == NULL) {
    cabeza = temp;
    cola = temp;
  }else if (cabeza->next == NULL){
    cabeza->next = temp;
    cola = temp;
  }else{
    cola->next = temp;
    cola = temp;
  }
}

void Lista::eliminarNodo(int indice){
  nodo* actual;
  nodo* anterior;
  bool isNull = false;

  actual = cabeza;

  if (indice == 1) {
    if (cabeza->next == NULL) {
      cabeza = NULL;
      cola = NULL;
    }else{
      cabeza = cabeza->next;
    }
  }else{
    for (int i = 1; i < indice; i++) {
      anterior = actual;

      if (actual->next == NULL) {
        cola = anterior;
        isNull = true;
        break;
      }else{
        actual = actual->next;
      }
    }

    if (!isNull) {
      anterior->next = actual->next;
    }

  }

  verificar();
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

void Lista::verificar(){
  if (cola == NULL && cabeza != NULL) {
    cola = cabeza;
  }

  if (cabeza == NULL && cola != NULL){
    cabeza = cola;
  }

}
