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

    void usunZPoczatku() {
        if (!poczatek) return;
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        if (poczatek) {
            poczatek->poprzedni = nullptr;
        }
        else {
            koniec = nullptr;
        }
        delete temp;
    }

    void usunZKonca() {
        if (!koniec) return;
        Wezel* temp = koniec;
        koniec = koniec->poprzedni;
        if (koniec) {
            koniec->nastepny = nullptr;
        }
        else {
            poczatek = nullptr;
        }
        delete temp;
    }

    void wyswietl() const {
        Wezel* obecny = poczatek;
        while (obecny) {
            std::cout << obecny->dane << " ";
            obecny = obecny->nastepny;
        }
        std::cout << std::endl;
    }

    void wyswietlOdKonca() const {
        Wezel* obecny = koniec;
        while (obecny) {
            std::cout << obecny->dane << " ";
            obecny = obecny->poprzedni;
        }
        std::cout << std::endl;
    }

    void wyczysc() {
        while (poczatek) {
            usunZPoczatku();
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
        std::cout << "3. Usun element z poczatku listy\n";
        std::cout << "4. Usun element z konca listy\n";
        std::cout << "5. Wyswietl cala liste\n";
        std::cout << "6. Wyswietl liste w odwrotnej kolejnosci\n";
        std::cout << "7. Czysc cala liste\n";
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
        case 3:
            lista.usunZPoczatku();
            break;
        case 4:
            lista.usunZKonca();
            break;
        case 5:
            std::cout << "Lista: ";
            lista.wyswietl();
            break;
        case 6:
            std::cout << "Lista w odwrotnej kolejnosci: ";
            lista.wyswietlOdKonca();
            break;
        case 7:
            lista.wyczysc();
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