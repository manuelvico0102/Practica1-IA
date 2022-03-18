#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){
    if(inicio_partida){
        int tam = mapaResultado.size();
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                if(i <= 2 || i >= tam-3 || j <= 2 || j >= tam-3){
                    mapaResultado[i][j] = 'P';
                }
            }
        }

        inicio_partida = false;
    }

	Action accion = actIDLE;
	//actualización del conocimiento
	switch(ultimaAccion){
		case actFORWARD:
			switch(brujula){
				case 0: fil--; break;		//Norte
				case 1: col++; break;		//Este
				case 2: fil++; break;		//Sur
				case 3: col--; break;		//Oeste
			}
			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			//girar_derecha = (rand()%2==0);
            girar_derecha = true;
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha = (rand()%2==0);
            //girar_derecha = false;
			break;
	}

	if(sensores.terreno[0] == 'G' and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
        brujula = sensores.sentido;
		bien_situado = true;
	}

	if(bien_situado){
		mapaResultado[fil][col] = sensores.terreno[0];
	}

    if(sensores.terreno[0] == 'D' and !zapatillas){
        zapatillas = true;
    }

    if(sensores.terreno[0] == 'K' and !bikini){
        bikini = true;
    }

	//Decidir la nueva accion
    if(((sensores.terreno[3] == 'G' and sensores.superficie[3] == '_')and sensores.superficie[3] == '_' ) or dir_cas3 > 0){
        if(dir_cas3 == 0){
            accion = actTURN_R;
            dir_cas3++;
        }else if(dir_cas3 == 1){
            accion = actFORWARD;
            dir_cas3++;
        }else if(dir_cas3 == 2){
            accion = actTURN_L;
            dir_cas3 = 0;
        }
    }else if((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or
            sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K') and sensores.superficie[2] == '_'){
		accion = actFORWARD;
	}else if((sensores.terreno[2] == 'B' and zapatillas) and sensores.superficie[2] == '_'){
        accion = actFORWARD;
    }else if((sensores.terreno[2] == 'A' and bikini) and sensores.superficie[2] == '_') {
        accion = actFORWARD;
    }else if(!girar_derecha){
        accion = actTURN_L;
    }else{
		accion = actTURN_R;
	}

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Este" << endl; break;
		case 2: cout << "Sur " << endl; break;
		case 3: cout << "Oeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;


	// Determinar el efecto de la ultima accion enviada
    if(sensores.terreno[1] == '?' and sensores.superficie[1] == '_'){
        girar_derecha = false;
    }
	ultimaAccion = accion;		//Recordamos última acción
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
