#ifndef JUEGO_H
#define JUEGO_H
#include <QDebug>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <sstream>

class juego
{
private:

    int elemento{1};  //valor que contendra la opcion tanto del usuario como de la computadora

    /* 1.-piedra
     * 2.-papel
     * 3.-tijera
     * 4.-lagarto
     * 5.-spock */

public:
    juego(); //constructor sin elementos
    juego(int); //constructor con parametro, de otro objeto de la misma clase
    ~juego();//destructor

    void setElemento(int);
    int getElemento();     //funciones del elemento 'elemento'

    int motor();

    void comparar(juego&,int&,int&);

};

#endif // JUEGO_H
