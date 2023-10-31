#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
#include <windows.h>
#include "juego.h"

using namespace std;

int main(int argc, char *argv[]) {
    system("color 8F");
    QCoreApplication a(argc, argv);

    do {
        int rondas = 7;
        int contadorUsuario = 0, contadorMaquina = 0;
        qInfo()<<"Hola este es el programa para jugar Piedra,Papel,Tijera,Lagarto,Spock\n\n";
        qInfo()<<"Reglas:\nLas tijeras cortan el papel, "
                   "el papel envuelve la piedra, la piedra aplasta "
                   "al lagarto, el lagarto envenena a Spock, Spock aplasta las tijeras, "
                   "las tijeras decapitan al lagarto, el lagarto devora el papel, "
                   "el papel desaprueba a Spock, Spock desintegra la piedra y, como "
                   "siempre, la piedra aplasta las tijeras.";

        qInfo()<<"\n\n\n\t\tVaz a jugar contra la computadora,\n\n";
        cout << "Bienvenido al juego. Gana el mejor de 4 rondas.\n";

        while (rondas > 0 && contadorUsuario < 4 && contadorMaquina < 4) {
            juego maquina{1};
            juego usuario{2};

            cout << "\n\nQue escoges?\n1)Piedra\n2)Papel\n3)Tijera\n4)Lagarto\n5)Spock\nTu eleccion: ";
            int valorElemento;
            cin >> valorElemento;
            usuario.setElemento(valorElemento);

            maquina.motor();    //en esta parte de la instruccion, le asignamos un numero aleatorio al objeto maquina.
            cout << "\n\nLa maquina selecciono la opcion: " << maquina.getElemento();
            usuario.comparar(maquina, contadorUsuario, contadorMaquina);

            cout << "\n\n\t\t\tMarcador\nTu: " << contadorUsuario << "\nLa Maquina: " << contadorMaquina;

            rondas--;
        }

        // Mostrar el resultado final del juego
        cout << "\nResultados finales:\n";
        cout << "Tus victorias: " << contadorUsuario << "\nVictorias de la maquina: " << contadorMaquina << "\n";

        if (contadorUsuario >= 4 || contadorUsuario>contadorMaquina) {
            cout << "Felicidades, ganaste el juego!" << endl;
        } else if (contadorMaquina >= 4 || contadorMaquina>contadorUsuario){
            cout << "La maquina gana el juego. Mejor suerte la proxima vez!" << endl;
        } else {
            cout << "La partida ha terminado en empate" << endl;
        }


        cout << "\nQuieres jugar otra vez? (1: Si, 0: No): ";
        int jugarOtraVez;
        cin >> jugarOtraVez;

        if (jugarOtraVez != 1) {
            break;
        }

    } while (true);

    return a.exec();
}
