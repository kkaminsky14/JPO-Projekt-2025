///Glowna klasa programu, odpowiedzialna za wyswietlanie menu kalkulatora oraz pobieranie inputu od uzytkownika
///Autor: Kacper Kaminski
///Data: 17.01.2025
#include "Kalkulator.h"
#include <iostream>
#include <string>

void Kalkulator::menu() {
    std::string inputwybor;
    int wybor{};

    while (true) {
        std::cout << "-----------------" << std::endl;
        std::cout << "Kalkulator" << std::endl;
        std::cout << "1. Dodaj" << std::endl;
        std::cout << "2. Odejmij" << std::endl;
        std::cout << "3. Pomnoz" << std::endl;
        std::cout << "4. Podziel" << std::endl;
        std::cout << "5. Pierwiastek" << std::endl;
        std::cout << "6. Konwertuj wynik (BIN, OCT, HEX)" << std::endl;
        std::cout << "7. Wyjdz" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> inputwybor;
        std::cout << "-----------------" << std::endl;

        // Zabezpieczenie przed przypadkowym podaniem przez uzytkownika czegos innego niz liczby od 1 do 7
        try {
            wybor = std::stoi(inputwybor);
        }
        catch (std::invalid_argument&) {
            std::cout << "Niepoprawny wybor. Nalezy podac liczbe." << std::endl;
            continue;
        }
        switch (wybor) {
        case 1:
            wynik = operacje.dodaj(input(), input());
            std::cout << "Wynik: " << wynik << std::endl;
            break;
        case 2:
            wynik = operacje.odejmij(input(), input());
            std::cout << "Wynik: " << wynik << std::endl;
            break;
        case 3:
            wynik = operacje.pomnoz(input(), input());
            std::cout << "Wynik: " << wynik << std::endl;
            break;
        case 4:
            try {
                wynik = operacje.podziel(input(), input());
                std::cout << "Wynik: " << wynik << std::endl;
            }
            //Sposob z lapaniem bledu poprzez invalid_argument& e i uzycie e.what() zostal wygenerowany przez ChatGPT
            catch (const std::invalid_argument& e) {
                std::cout << "Blad: " << e.what() << std::endl; 
            }
            break;
        case 5:
            try {
                wynik = operacje.pierwiastek(input());
                std::cout << "Wynik: " << wynik << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Blad: " << e.what() << std::endl; 
            }
            break;
        case 6:
            konwersja();
            break;
        case 7:
            std::cout << "Program zostal zamkniety." << std::endl;
            return;
        default:
            std::cout << "Niepoprawny wybor." << std::endl;
            break;
        }
    }
}

// Funkcja odpowiedzialna za pobranie inputu od uzytkownika
float Kalkulator::input() {
    std::cout << "Podaj liczbe: " << std::endl;
    std::string inputliczba;
    float liczba{};
    std::cin >> inputliczba;
    try {
        liczba = std::stof(inputliczba);
    }
    catch (std::invalid_argument&) {
        std::cout << "Niepoprawny input. Nalezy podac liczbe" << std::endl;
        return input();
    }
    return liczba;
}
// Funkcja odpowiedzialna za konwersje wyniku miedzy systemami liczbowymi BIN/OCT/HEX
void Kalkulator::konwersja() {
    std::cout << "Konwersja wyniku" << std::endl;
    std::cout << "1. BIN" << std::endl;
    std::cout << "2. OCT" << std::endl;
    std::cout << "3. HEX" << std::endl;
    std::cout << "Wybierz opcje: " << std::endl;
    std::string inputwybor;
    int wybor{};
    std::cin >> inputwybor;
    try {
        wybor = std::stoi(inputwybor);
    }
    catch (std::invalid_argument&) {
        std::cout << "Niepoprawny wybor. Podaj liczbe od 1 do 3." << std::endl;
        return konwersja();
    }
    if (wynik < 0 || floor(wynik) != wynik) {
        std::cout << "Blad. Nalezy podac liczbe calkowita nieujemna." << std::endl;
        return;
    }

    int wynikkonwertuj = static_cast<int>(wynik);

    switch (wybor) {
    case 1:
        std::cout << "BIN: " << konwersje.Binary(wynikkonwertuj) << std::endl;
        break;
    case 2:
        std::cout << "OCT: " << konwersje.Octal(wynikkonwertuj) << std::endl;
        break;
    case 3:
        std::cout << "HEX: " << konwersje.Hexadecimal(wynikkonwertuj) << std::endl;
        break;
    }
}