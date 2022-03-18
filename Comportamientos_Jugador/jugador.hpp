#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil = col = 99;		//valor por defecto 99
      brujula = 0;			//0-> norte, 1-> este, 2-> sur, 3-> oeste
      ultimaAccion = actIDLE;
      girar_derecha = false;
      avanzadas = 0;
      bien_situado = false;
      dir_cas3 = dir_cas1 = 0;
      inicio_partida = true;
      bikini = zapatillas = false;
      no_descubierta = false;
      cargado = true;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Declarar aquí las variables de estado
  	int fil, col, brujula;
  	Action ultimaAccion;
  	bool girar_derecha, bien_situado;
    int avanzadas;
    int dir_cas3, dir_cas1;
    int cargado;
    bool inicio_partida;
    bool bikini, zapatillas;
    bool no_descubierta;
};

#endif
