///Klasa obslugujaca operacje matematyczne
///Autor: Kacper Kaminski
///Data: 17.01.2025
#include "Matematyka.h"
#include <iostream>
#include <cmath>

float Matematyka::dodaj(float a, float b) {
    return b + a;
}

float Matematyka::odejmij(float a, float b) {
    return b - a;
}

float Matematyka::pomnoz(float a, float b) {
    return b * a;
}

float Matematyka::podziel(float a, float b) {
    if (a == 0) {
        throw std::invalid_argument("Blad. Liczba musi byc rozna od zera");
    }
    return b / a;
}

float Matematyka::pierwiastek(float a) {
    if (a < 0) {
        throw std::invalid_argument("Blad. Liczba musi byc nieujemna");
    }
    return sqrt(a);
}