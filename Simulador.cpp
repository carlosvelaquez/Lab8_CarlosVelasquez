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

          vector<string> s;
          s.clear();

          switch (op) {
            case 1:{
              Aprendiz* a = new Aprendiz(s);
              a->setNombre(nombre);

              luchadores->anadir(a);
              break;
            }
            case 2:{
              Guerrero* a = new Guerrero(s);
              a->setNombre(nombre);

              luchadores->anadir(a);
              break;
            }
            case 3:{
              Mago* a = new Mago(s);
              a->setNombre(nombre);

              luchadores->anadir(a);
              break;
            }
            case 4:{
              Alquimista* a = new Alquimista(s);
              a->setNombre(nombre);

              luchadores->anadir(a);
              break;
            }
            case 5:{
              DragonBorn* a = new DragonBorn(s);
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

        if (luchadores->size() < 1) {
          cout << "No hay luchadores para modificar." << endl;
          break;
        }

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
        cout << "------------------------------" << endl;

        switch (opc) {
          case 1:{
            string nNombre;
            cout << "Nuevo nombre: ";
            cin >> nNombre;

            luchadorSeleccionado->setNombre(nNombre);
            cout << "Nombre modificado exitosamente." << endl;
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
      case 4:{
        iniciarSimulacion();
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
    cout << i << ". " << luchadores->at(i)->getNombre() << " | " << "EXP: " << luchadores->at(i)->getExp() << " | " << luchadores->at(i)->getClasesAprendidas() << " Clases Aprendidas" << endl;
  }

  if (luchadores->size() <= 0) {
    cout << "No hay luchadores que mostrar." << endl;
  }
}

void Simulador::iniciarSimulacion(){
  Luchador* luchador1;
  Luchador* luchador2;

  cout << "Iniciando Simulación..." << endl;

  int op1, op2;
  listarLuchadores();
  cout << "Seleccione al Luchador 1 - ";

  cin >> op1;
  cout << "Seleccione al Luchador 2 - ";
  cin >> op2;
  cout << "------------------------------" << endl;


  if (op1 < 1 || op1 > luchadores->size() || op2 < 1 || op2 > luchadores->size()) {
    cout << "[ERROR] Uno de los números ingresados supera al tamaño de la lista.";
  }else{
    luchador1 = luchadores->at(op1);
    luchador2 = luchadores->at(op2);

    simular(luchador1, luchador2);
  }

}

void Simulador::simular(Luchador* luchador1, Luchador* luchador2){
  bool termino = false;
  int turno = 0;
  int dano1 = 0;
  int dano2 = 0;

  while (!termino) {
    int op;
    bool continuar = false;
    turno ++;

    while(!continuar){
      continuar = true;
      mostrarStats(luchador1, luchador2);
      cout << "------------------------------" << endl;
      cout << "Es el turno de " << luchador1->getNombre() << endl
      << "¿Cual será su movimiento?" << endl << endl
      << "1. Ataque Mágico" << endl
      << "2. Ataque Físico" << endl
      << "3. Defender" << endl
      << "4. Habilidad Especial" << endl << endl
      << "Ingrese el número de la opción que desea - ";
      cin >> op;
      cout << "------------------------------" << endl;


      switch (op) {
        case 1:{
          if (luchador1->getAtaqueMagico() == 0) {
            cout << "¡" << luchador1->getNombre() << " no tiene ataque mágico!" << endl;
            continuar = false;
          }else{
            cout << "¡" << luchador1->getNombre() << " ha usado su ataque mágico!" << endl;
            if (luchador2->isDefendiendose()) {
              dano2 = luchador1->getAtaqueMagico() - (luchador2->getDefensaMagica()*luchador1->getAtaqueMagico());
            }else{
              dano2 = luchador1->getAtaqueMagico();
            }

            cout << "¡" << luchador2->getNombre() << " toma " << dano2 << " de daño!" << endl;
            luchador2->setHP(luchador2->getHP()-dano2);
            luchador2->setUltimoDano(dano2);
          }
          break;
        }
        case 2:{
          if (luchador1->getAtaqueFisico() == 0) {
            cout << "¡" << luchador1->getNombre() << " no tiene ataque físico!" << endl;
            continuar = false;
          }else{
            cout << "¡" << luchador1->getNombre() << " ha usado su ataque físico!" << endl;

            if (luchador2->isDefendiendose()) {
              dano2 = luchador1->getAtaqueFisico() - (luchador2->getDefensaFisica()*luchador1->getAtaqueFisico());
            }else{
              dano2 = luchador1->getAtaqueFisico();
            }

            cout << "¡" << luchador2->getNombre() << " toma " << dano2 << " de daño!" << endl;
            luchador2->setHP(luchador2->getHP()-dano2);
            luchador2->setUltimoDano(dano2);
          }
          break;
        }
        case 3:{
          cout << "¡" << luchador1->getNombre() << " se está defendido!" << endl;
          int rec = (luchador1->getHP()*.45);
          cout << "¡" << luchador1->getNombre() << " recupera " << rec << " HP!" << endl;
          luchador1->setHP(luchador1->getHP() + rec);
          luchador1->setDefendiendose(true);
          break;
        }case 4:{
          if (luchador1->usoHabilidad()) {
            cout << "¡" << luchador1->getNombre() << " ya usó su habilidad!" << endl;
            continuar = false;
          }else{
            if (luchador1->getHabilidadesEspeciales().size() <= 0) {
              cout << "¡" << luchador1->getNombre() << " no tiene habilidades especiales!" << endl;
              cout << "------------------------------" << endl;
              break;
            }

            int opc;
            cout << "Habilidades de " << luchador1->getNombre() << endl;

            for (int i = 0; i < luchador1->getHabilidadesEspeciales().size(); i++) {
              cout << i << ". " << (typeid(luchador1->getHabilidadesEspeciales().at(i))).name() << endl;
            }

            cout << endl << "¿Que habilidad desea usar? - ";
            cin >> opc;

            if (opc >= luchador1->getHabilidadesEspeciales().size() || opc < 0) {
              cout << "[ERROR] El número ingresado supera al tamaño de la lista.";
              continuar = false;
              break;
            }else{
              luchador1->setHabilidad(true);
              cout << "¡" << luchador1->getNombre() << " ha usado una habilidad!" << endl;
              ((HabilidadEspecial*) luchador1->getHabilidadesEspeciales().at(opc))->aplicar(luchador1);
            }
          }
          break;
        }
        default:{
          cout << "Opción inválida, por favor intente de nuevo." << endl;
          continuar = false;
          break;
        }
      }
    }

    continuar = false;
    luchador2->setDefendiendose(false);
    luchador2->setTurnos(turno);

    if (luchador1->getHP() < 1 || luchador2->getHP() < 1 ) {
      termino = true;
      break;
    }

    while(!continuar){
      continuar = true;
      mostrarStats(luchador1, luchador2);
      cout << "------------------------------" << endl;
      cout << "Es el turno de " << luchador2->getNombre() << endl
      << "¿Cual será su movimiento?" << endl << endl
      << "1. Ataque Mágico" << endl
      << "2. Ataque Físico" << endl
      << "3. Defender" << endl
      << "4. Habilidad Especial" << endl << endl
      << "Ingrese el número de la opción que desea - ";
      cin >> op;
      cout << "------------------------------" << endl;


      switch (op) {
        case 1:{
          if (luchador2->getAtaqueMagico() == 0) {
            cout << "¡" << luchador2->getNombre() << " no tiene ataque mágico!" << endl;
            continuar = false;
          }else{
            cout << "¡" << luchador2->getNombre() << " ha usado su ataque mágico!" << endl;
            if (luchador1->isDefendiendose()) {
              dano1 = luchador2->getAtaqueMagico() - (luchador1->getDefensaMagica()*luchador2->getAtaqueMagico());
            }else{
              dano1 = luchador2->getAtaqueMagico();
            }

            cout << "¡" << luchador1->getNombre() << " toma " << dano1 << " de daño!" << endl;
            luchador1->setHP(luchador1->getHP()-dano1);
            luchador1->setUltimoDano(dano1);
          }
          break;
        }
        case 2:{
          if (luchador2->getAtaqueFisico() == 0) {
            cout << "¡" << luchador2->getNombre() << " no tiene ataque físico!" << endl;
            continuar = false;
          }else{
            cout << "¡" << luchador2->getNombre() << " ha usado su ataque físico!" << endl;

            if (luchador1->isDefendiendose()) {
              dano1 = luchador2->getAtaqueFisico() - (luchador1->getDefensaFisica()*luchador2->getAtaqueFisico());
            }else{
              dano1 = luchador2->getAtaqueFisico();
            }

            cout << "¡" << luchador1->getNombre() << " toma " << dano1 << " de daño!" << endl;
            luchador1->setHP(luchador1->getHP()-dano1);
            luchador1->setUltimoDano(dano1);
          }
          break;
        }
        case 3:{
          cout << "¡" << luchador2->getNombre() << " se está defendido!" << endl;
          int rec = (luchador2->getHP()*.45);
          cout << "¡" << luchador2->getNombre() << " recupera " << rec << " HP!" << endl;
          luchador2->setHP(luchador2->getHP() + rec);
          luchador2->setDefendiendose(true);
          break;
        }case 4:{
          cout << "¡" << luchador1->getNombre() << " ya usó su habilidad!" << endl;
          if (luchador2->usoHabilidad()) {
            continuar = false;
          }else{
            if (luchador2->getHabilidadesEspeciales().size() <= 0) {
              cout << "¡" << luchador2->getNombre() << " no tiene habilidades especiales!" << endl;
              cout << "------------------------------" << endl;
              break;
            }

            int opc;
            cout << "Habilidades de " << luchador2->getNombre() << endl;

            for (int i = 0; i < luchador2->getHabilidadesEspeciales().size(); i++) {
              cout << i << ". " << (typeid(luchador2->getHabilidadesEspeciales().at(i))).name() << endl;
            }

            cout << endl << "¿Que habilidad desea usar? - ";
            cin >> opc;

            if (opc >= luchador2->getHabilidadesEspeciales().size() || opc < 0) {
              cout << "[ERROR] El número ingresado supera al tamaño de la lista.";
              continuar = false;
              break;
            }else{
              luchador2->setHabilidad(true);
              cout << "¡" << luchador2->getNombre() << " ha usado una habilidad!" << endl;
              ((HabilidadEspecial*) luchador2->getHabilidadesEspeciales().at(opc))->aplicar(luchador2);
            }
          }
          break;
        }
        default:{
          cout << "Opción inválida, por favor intente de nuevo." << endl;
          continuar = false;
          break;
        }
      }
    }

    if (luchador1->getHP() < 1 || luchador2->getHP() < 1 ) {
      termino = true;
    }

    luchador1->setDefendiendose(false);
    luchador1->setTurnos(turno);
  }

  for (int i = 1; i <= luchadores->size(); i++) {
    if (luchadores->at(i)->getHP() <= 0) {
      cout << "¡" << luchadores->at(i)->getNombre() << " ha muerto!" << endl;
      luchadores->eliminarNodo(i);
      break;
    }
  }
}

void Simulador::mostrarStats(Luchador* luchador1, Luchador* luchador2){
  cout << "Estadísticas de Combate" << endl << endl
  << luchador1->getNombre() << " | " << "HP: " << luchador1->getHP() << endl
  << luchador2->getNombre() << " | " << "HP: " << luchador2->getHP() << endl;
}
