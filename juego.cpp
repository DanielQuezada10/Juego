#include "juego.h"
#include <QDebug>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;

juego::juego(){
    qInfo()<<"\nIniciando constructor\n";
}

juego::juego(int elemento){
    //constructor que recibe elementos.
}
juego::~juego(){

    qInfo()<<"\nInvocando al destructor";
}

void juego::setElemento(int elemento){
    this->elemento=elemento;
}

int juego::getElemento(){
    return elemento;
}

void juego::comparar(juego &otro,int& contadorusuario,int& contadormaquina){


    if(this->elemento==1){                            //Caso en donde el usuario escoje piedra
        if(otro.elemento==3||otro.elemento==4){       //gana contra tijera y lagarto
            qInfo()<<"\nEste Round lo ganas tu\n";
            contadorusuario++;
        }
        else if(otro.elemento==2||otro.elemento==5){  //pierde contra papel y spock
            qInfo()<<"\nEste Round lo gana la maquina\n";
            contadormaquina++;
        }
        else{
            qInfo()<<"\nEmpate\n";
        }
    }
    else if(this->elemento==2){                     //Caso donde el usuario escoje papel
        if(otro.elemento==1||otro.elemento==5){     //gana contra piedra y spock
            qInfo()<<"\nEste Round lo ganas tu\n";
            contadorusuario++;
        }
        else if(otro.elemento==3||otro.elemento==4){ //pierde contra tijera y lagarto
            qInfo()<<"\nEste Round lo gano la maquina\n";
            contadormaquina++;
        }
        else{
            qInfo()<<"\nEmpate\n";
        }
    }
    else if(this->elemento==3){                     //Caso donde el usuario escoje Tijera
        if(otro.elemento==2||otro.elemento==4){     //gana contra papel y lagarto
            qInfo()<<"\nEste Round lo ganas tu\n";
            contadorusuario++;
        }
        else if(otro.elemento==1||otro.elemento==5){ //pierde contra piedra y spock
            qInfo()<<"\nEste Round lo gano la maquina\n";
            contadormaquina++;
        }
        else{
            qInfo()<<"\nEmpate\n";
        }
    }
    else if(this->elemento==4){                     //Caso donde el usuario escoje Lagarto
        if(otro.elemento==2||otro.elemento==5){     //gana contra papel y spock
            qInfo()<<"\nEste Round lo ganas tu\n";
            contadorusuario++;
        }
        else if(otro.elemento==1||otro.elemento==3){ //pierde contra piedra y tijera
            qInfo()<<"\nEste Round lo gano la maquina\n";
            contadormaquina++;
        }
        else{
            qInfo()<<"\nEmpate\n";
        }
    }
    else if(this->elemento==5){                     //Caso donde el usuario escoje spock
        if(otro.elemento==3||otro.elemento==1){     //gana contra tijeras y piedra
            qInfo()<<"\nEste Round lo ganas tu\n";
            contadorusuario++;
        }
        else if(otro.elemento==4||otro.elemento==2){ //pierde contra lagarto y papel
            qInfo()<<"\nEste Round lo gano la maquina\n";
            contadormaquina++;
        }
        else{
            qInfo()<<"\nEmpate\n";
        }
    }
    else{
        qInfo()<<"\nNo selecciono ninguna opcion valida\n";
    }

}
int juego::motor(){
    int valorM{0};
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(semilla);
    uniform_int_distribution<int>distribucionEntera{1,5};
    valorM=distribucionEntera(motor);
    this->elemento=distribucionEntera(motor);
    return valorM;
}
