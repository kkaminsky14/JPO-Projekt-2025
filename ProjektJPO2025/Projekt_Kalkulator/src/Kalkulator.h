#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "Matematyka.h"
#include "Konwersja.h"

class Kalkulator {
public:
    void menu();

private:
    Matematyka operacje;
    Konwersja konwersje;
    float wynik{};
    float input();
    void konwersja();
};
#endif