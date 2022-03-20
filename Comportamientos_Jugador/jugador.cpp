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

            if(sensores.bateria >= 4500)
                cargado = true;
            else
                cargado = false;

			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			girar_derecha = (rand()%2==0);

            if(sensores.bateria >= 4500)
                cargado = true;
            else
                cargado = false;
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha = (rand()%2==0);

            if(sensores.bateria >= 4500)
                cargado = true;
            else
                cargado = false;

			break;
        case actIDLE:
            if(sensores.bateria >= 4500)
                cargado = true;
            else
                cargado = false;

            break;

	}

    if(sensores.reset == true) {
        bien_situado = false;
        bikini = false;
        zapatillas = false;
    }

	if(sensores.terreno[0] == 'G' and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
        brujula = sensores.sentido;
		bien_situado = true;
	}

	if(bien_situado){
		mapaResultado[fil][col] = sensores.terreno[0];
        if(sensores.sentido == 0) {                                         //Mirando al norte
            mapaResultado[fil-1][col-1] = sensores.terreno[1];
            mapaResultado[fil-1][col] = sensores.terreno[2];
            mapaResultado[fil-1][col+1] = sensores.terreno[3];
            mapaResultado[fil-2][col-2] = sensores.terreno[4];
            mapaResultado[fil-2][col-1] = sensores.terreno[5];
            mapaResultado[fil-2][col] = sensores.terreno[6];
            mapaResultado[fil-2][col+1] = sensores.terreno[7];
            mapaResultado[fil-2][col+2] = sensores.terreno[8];
            mapaResultado[fil-3][col-3] = sensores.terreno[9];
            mapaResultado[fil-3][col-2] = sensores.terreno[10];
            mapaResultado[fil-3][col-1] = sensores.terreno[11];
            mapaResultado[fil-3][col] = sensores.terreno[12];
            mapaResultado[fil-3][col+1] = sensores.terreno[13];
            mapaResultado[fil-3][col+2] = sensores.terreno[14];
            mapaResultado[fil-3][col+3] = sensores.terreno[15];
        }else if(sensores.sentido == 1){                                    //Mirando al este
            mapaResultado[fil-1][col+1] = sensores.terreno[1];
            mapaResultado[fil][col+1] = sensores.terreno[2];
            mapaResultado[fil+1][col+1] = sensores.terreno[3];
            mapaResultado[fil-2][col+2] = sensores.terreno[4];
            mapaResultado[fil-1][col+2] = sensores.terreno[5];
            mapaResultado[fil][col+2] = sensores.terreno[6];
            mapaResultado[fil+1][col+2] = sensores.terreno[7];
            mapaResultado[fil+2][col+2] = sensores.terreno[8];
            mapaResultado[fil-3][col+3] = sensores.terreno[9];
            mapaResultado[fil-2][col+3] = sensores.terreno[10];
            mapaResultado[fil-1][col+3] = sensores.terreno[11];
            mapaResultado[fil][col+3] = sensores.terreno[12];
            mapaResultado[fil+1][col+3] = sensores.terreno[13];
            mapaResultado[fil+2][col+3] = sensores.terreno[14];
            mapaResultado[fil+3][col+3] = sensores.terreno[15];
        }else if(sensores.sentido == 2) {                                   //Mirando al sur
            mapaResultado[fil+1][col+1] = sensores.terreno[1];
            mapaResultado[fil+1][col] = sensores.terreno[2];
            mapaResultado[fil+1][col-1] = sensores.terreno[3];
            mapaResultado[fil+2][col+2] = sensores.terreno[4];
            mapaResultado[fil+2][col+1] = sensores.terreno[5];
            mapaResultado[fil+2][col] = sensores.terreno[6];
            mapaResultado[fil+2][col-1] = sensores.terreno[7];
            mapaResultado[fil+2][col-2] = sensores.terreno[8];
            mapaResultado[fil+3][col+3] = sensores.terreno[9];
            mapaResultado[fil+3][col+2] = sensores.terreno[10];
            mapaResultado[fil+3][col+1] = sensores.terreno[11];
            mapaResultado[fil+3][col] = sensores.terreno[12];
            mapaResultado[fil+3][col-1] = sensores.terreno[13];
            mapaResultado[fil+3][col-2] = sensores.terreno[14];
            mapaResultado[fil+3][col-3] = sensores.terreno[15];
        }else if(sensores.sentido == 3) {                                   //Mirando al oeste
            mapaResultado[fil+1][col-1] = sensores.terreno[1];
            mapaResultado[fil][col-1] = sensores.terreno[2];
            mapaResultado[fil-1][col-1] = sensores.terreno[3];
            mapaResultado[fil+2][col-2] = sensores.terreno[4];
            mapaResultado[fil+1][col-2] = sensores.terreno[5];
            mapaResultado[fil][col-2] = sensores.terreno[6];
            mapaResultado[fil-1][col-2] = sensores.terreno[7];
            mapaResultado[fil-2][col-2] = sensores.terreno[8];
            mapaResultado[fil+3][col-3] = sensores.terreno[9];
            mapaResultado[fil+2][col-3] = sensores.terreno[10];
            mapaResultado[fil+1][col-3] = sensores.terreno[11];
            mapaResultado[fil][col-3] = sensores.terreno[12];
            mapaResultado[fil-1][col-3] = sensores.terreno[13];
            mapaResultado[fil-2][col-3] = sensores.terreno[14];
            mapaResultado[fil-3][col-3] = sensores.terreno[15];
        }
	}

    if(sensores.terreno[0] == 'D' and !zapatillas){
        zapatillas = true;
    }

    if(sensores.terreno[0] == 'K' and !bikini){
        bikini = true;
    }

	//Decidir la nueva accion
    if((sensores.terreno[3] == 'M' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P' &&
        sensores.superficie[7] == '_' && sensores.terreno[2] != 'M') || saliendo > 0){
        if(saliendo <= 1) {             //Se hará dos veces
            accion = actFORWARD;
            saliendo++;
        }else if(saliendo == 2){
            accion = actTURN_R;
            saliendo = 0;
        }
    }else if((sensores.terreno[1] == 'M' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P'
               && sensores.superficie[5] == '_' && sensores.terreno[2] != 'M') || saliendo > 0){
        if(saliendo <= 1) {             //Se hará dos veces
            accion = actFORWARD;
            saliendo++;
        }else if(saliendo == 2){
            accion = actTURN_L;
            saliendo = 0;
        }
    }else if((sensores.terreno[2] == 'X' || sensores.terreno[6]=='X' || sensores.terreno[12] =='X' || sensores.terreno[0] == 'X') && !cargado){
        if(sensores.terreno[0] != 'X')
            accion = actFORWARD;
        else
            accion = actIDLE;
    }else if(((sensores.terreno[3] == 'G' or sensores.terreno[3] == 'X' or sensores.terreno[3] == 'K' or
                sensores.terreno[3] == 'D')and sensores.superficie[3] == '_' ) or dir_cas3 > 0){
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
    }else if(((sensores.terreno[1] == 'G' or sensores.terreno[1] == 'X' or sensores.terreno[1] == 'K' or
               sensores.terreno[1] == 'D')and sensores.superficie[1] == '_' ) or dir_cas1 > 0) {
        if (dir_cas1 == 0) {
            accion = actTURN_L;
            dir_cas1++;
        } else if (dir_cas1 == 1) {
            accion = actFORWARD;
            dir_cas1++;
        } else if (dir_cas1 == 2) {
            accion = actTURN_R;
            dir_cas1 = 0;
        }
    }else if(avanzadas >= 10 || sensores.terreno[2] == 'P' || sensores.terreno[2] == 'M' ||
            (sensores.terreno[2] == 'A' && !bikini /*&& sensores.bateria <= 4980*/) ||
            (sensores.terreno[2] == 'B' && !zapatillas /*&& sensores.bateria <= 4800*/)){
        avanzadas = 0;
        if(girar_derecha)
            accion = actTURN_R;
        else
            accion = actTURN_L;

    }else if((sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' ||
            sensores.terreno[2] == 'D' || sensores.terreno[2] == 'K' || sensores.terreno[2] == 'X' ||
            (sensores.terreno[2] == 'B' && zapatillas) || (sensores.terreno[2] == 'A' && bikini) /*||
            (sensores.terreno[2] == 'B' && !zapatillas && sensores.bateria >=4800) ||
            (sensores.terreno[2] == 'A' && !bikini && sensores.bateria >=4980)*/) && sensores.superficie[2] == '_'){
		accion = actFORWARD;
        avanzadas++;
	}/*else if((sensores.terreno[2] == 'B' and zapatillas) and sensores.superficie[2] == '_'){
        accion = actFORWARD;
        avanzadas++;
    }else if((sensores.terreno[2] == 'A' and bikini) and sensores.superficie[2] == '_') {
        accion = actFORWARD;
        avanzadas++;
    }/*else if(!girar_derecha){
        accion = actTURN_L;
    }else{
		accion = actTURN_R;
	}*/

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
	ultimaAccion = accion;		//Recordamos última acción
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
