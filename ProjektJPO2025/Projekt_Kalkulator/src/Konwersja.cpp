///Klasa obslugujaca konwersje miedzy systemami liczbowymi BIN,OCT,HEX
///Autor: Kacper Kaminski
///Data: 17.01.2025
#include "Konwersja.h"

std::string Konwersja::Binary(int liczba) {
    std::string bin = "";
    if (liczba == 0) {
        return "0";
    }
    while (liczba > 0) {
        bin = std::to_string(liczba % 2) + bin;
        liczba = liczba / 2;
    }
    return bin;
}
std::string Konwersja::Octal(int liczba) {
    std::string oct = "";
    if (liczba == 0) {
        return "0";
    }
    while (liczba > 0) {
        oct = std::to_string(liczba % 8) + oct;
        liczba = liczba / 8;
    }
    return oct;
}
// Przeksztalcanie liczby do postaci heksadecymalnej zostalo wygenerowane za pomoca ChatGPT
std::string Konwersja::Hexadecimal(int liczba) {
    std::string hex = "";
    const std::string hexsymbol = "0123456789ABCDEF";
    if (liczba == 0) {
        return "0";
    }
    while (liczba > 0) {
        hex = hexsymbol[liczba % 16] + hex;
        liczba = liczba / 16;
    }
    return hex;
}
