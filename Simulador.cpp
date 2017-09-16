#include "Simulador.h"

Simulador::Simulador(Lista* nLista){
  luchadores = nLista;
}

void Simulador::comenzar(){
  bool salir = false;

  while (!salir) {
    switch (menu()) {
      case 1:{
        cout << "Agregar Luchador" << endl << endl
        << "Ingrese los datos requeridos: " << endl
        << "Nombre: ";

        string nombre;
        cin >> nombre;
        bool salirSel = false;

        while(!salirSel){
          salirSel = true;

          cout << endl << "Clase Inicial" << endl
          << "1. Aprendiz" << endl
          << "2. Guerrero" << endl
          << "3. Mago" << endl
          << "4. Alquimista" << endl
          << "5. DragonBorn" << endl << endl
          << "Ingrese el número de la opción que desea - ";

          int op;
          cin >> op;

          switch (op) {
            case 1:{
              vector<string> s;
              s.clear();

              Aprendiz* a = new Aprendiz(s);
              a->setNombre(nombre);

              luchadores->anadir(a);
              break;
            }
            default:{
              cout << "------------------------------" << endl;
              cout << "Opción Inválida, por favor intente de nuevo." << endl;
              salirSel = false;
              break;
            }
          }
        }

        cout << "------------------------------" << endl;
        cout << "Luchador añadido con exito." << endl;
        break;
      }
      case 2:{
        bool salirSel = false;
        Luchador* luchadorSeleccionado;
        int op;

        while(!salirSel){
          salirSel = true;
          listarLuchadores();
          cout << endl << "¿Que luchador desea modificar? - ";

          cin >> op;
          cout << "------------------------------" << endl;

          if (op > luchadores->size() || op < 1) {
            salirSel = false;
            cout << "El número ingresado supera al tamaño de la lista." << endl;
            cout << "------------------------------" << endl;
          }else{
            luchadorSeleccionado = luchadores->at(op);
          }
        }

        int opc;

        cout << "¿Que atributo desea modificar?" << endl << endl
        << "1. Nombre del Luchador" << endl
        << "2. Clase del Luchador" << endl << endl
        << "Ingrese el número de la opción que desea - ";

        cin >> opc;

        switch (op) {
          case 1:{
            break;
          }
          default:{
            cout << "Opción Inválida, por favor intente de nuevo." << endl;
            break;
          }
        }
        break;
      }
      case 3:{
        listarLuchadores();
        break;
      }
      case 5:{
        salir = true;
        cout << "Saliendo..." << endl;
        cout << "------------------------------" << endl;
        break;
      }
      default:{
        cout << "Opción inválida, por favor intente de nuevo." << '\n';
        break;
      }
    }
  }
}

int Simulador::menu(){
  int opcion;

  cout << "------------------------------" << endl
  << "Menú del Simulador" << endl << endl
  << "1. Agregar Luchador" << endl
  << "2. Modificar Luchador" << endl
  << "3. Listar Luchadores" << endl
  << "4. Iniciar Simulación" << endl
  << "5. Salir del Programa" << endl << endl
  << "Ingrese el número de la opción que desea - ";

  cin >> opcion;
  cout << "------------------------------" << endl;
  return opcion;
}

void Simulador::listarLuchadores(){
  cout << "Lista de Luchadores" << endl << endl;

  for (int i = 1; i <= luchadores->size(); i++) {
    cout << i << ". " << luchadores->at(i)->getNombre() << " | " << luchadores->at(i)->getClasesAprendidas() << " Clases Aprendidas" << endl;
  }

  if (luchadores->size() <= 0) {
    cout << "No hay luchadores que mostrar." << endl;
  }
}
