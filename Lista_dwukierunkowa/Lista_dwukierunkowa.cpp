#include <iostream>

class ListaDwukierunkowa {
private:
    struct Wezel {
        int dane;
        Wezel* poprzedni;
        Wezel* nastepny;

        Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
    };

    Wezel* poczatek;
    Wezel* koniec;

public:
    // Konstruktor klasy
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr) {}

    // Destruktor - wywołuje metodę 'wyczysc'
    ~ListaDwukierunkowa() {
        wyczysc();
    }
    void wyczysc() {}
};
