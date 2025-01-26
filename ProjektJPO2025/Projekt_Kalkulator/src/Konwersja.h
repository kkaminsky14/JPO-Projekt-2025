#ifndef KONWERSJA_H
#define KONWERSJA_H
#include <string>

class Konwersja {
public:
    std::string Binary(int liczba);
    std::string Octal(int liczba);
    std::string Hexadecimal(int liczba);
};
#endif