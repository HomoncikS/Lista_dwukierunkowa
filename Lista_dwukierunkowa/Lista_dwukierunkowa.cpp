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
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr) {}

    ~ListaDwukierunkowa() {
        wyczysc();
    }
    void wyczysc() {}

    void dodajNaPoczatek(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc);
        if (!poczatek) {
            poczatek = koniec = nowyWezel;
        }
        else {
            nowyWezel->nastepny = poczatek;
            poczatek->poprzedni = nowyWezel;
            poczatek = nowyWezel;
        }
    }

    void dodajNaKoniec(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc);
        if (!koniec) {
            poczatek = koniec = nowyWezel;
        }
        else {
            nowyWezel->poprzedni = koniec;
            koniec->nastepny = nowyWezel;
            koniec = nowyWezel;
        }
    }
};

int main() {
    ListaDwukierunkowa lista;
    int wybor, wartosc, indeks;
    // Wywołanie metod
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Dodaj element na poczatek listy\n";
        std::cout << "2. Dodaj element na koniec listy\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor) {
        case 1:
            std::cout << "Podaj wartosc do dodania na poczatek: ";
            std::cin >> wartosc;
            lista.dodajNaPoczatek(wartosc);
            break;
        case 2:
            std::cout << "Podaj wartosc do dodania na koniec: ";
            std::cin >> wartosc;
            lista.dodajNaKoniec(wartosc);
            break;
        case 0:
            std::cout << "Koniec programu.\n";
            return 0;
        default:
            std::cout << "Niepoprawna opcja. Sprobuj ponownie.\n";
            break;
        }
    }
}