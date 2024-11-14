#include <iostream>

class ListaDwukierunkowa {
private:
    // Struktura Wezel reprezentuje pojedynczy element listy dwukierunkowej
    struct Wezel {
        int dane; // Przechowywana wartość w węźle
        Wezel* poprzedni; // Wskaźnik na poprzedni węzeł
        Wezel* nastepny; // Wskaźnik na następny węzeł
        // Konstruktor przypisujący węzeł z wartością oraz ustawiający wskaźniki na nullptr
        Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
    };

    Wezel* poczatek; // Wskaźnik na pierwszy element listy
    Wezel* koniec; // Wskaźnik na ostatni element listy

public:
    // Konstruktor klasy
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr) {}

    // Destruktor - wywołuje metodę 'wyczysc'
    ~ListaDwukierunkowa() {
        wyczysc();
    }

    // Metoda dodająca element na początek listy
    void dodajNaPoczatek(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc); // Tworzy nowy węzeł
        if (!poczatek) { // Jeśli lista jest pusta
            poczatek = koniec = nowyWezel; // Początek i koniec wskazują na nowy węzeł
        }
        else {
            nowyWezel->nastepny = poczatek; // Nowy węzeł wskazuje na aktualny początek
            poczatek->poprzedni = nowyWezel; // Aktualny początek wskazuje na nowy węzeł jako poprzedni
            poczatek = nowyWezel; // Początek listy przesuwa się na nowy węzeł
        }
    }

    // Metoda dodająca element na koniec listy
    void dodajNaKoniec(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc); // Tworzy nowy węzeł
        if (!koniec) { // Jeśli lista jest pusta
            poczatek = koniec = nowyWezel; // Początek i koniec wskazują na nowy węzeł
        }
        else {
            nowyWezel->poprzedni = koniec; // Nowy węzeł wskazuje na aktualny koniec
            koniec->nastepny = nowyWezel; // Aktualny koniec wskazuje na nowy węzeł jako następny
            koniec = nowyWezel; // Koniec listy przesuwa się na nowy węzeł
        }
    }

    // Metoda dodająca element na określonym indeksie
    void dodajNaIndeksie(int indeks, int wartosc) {
        if (indeks == 0) { // Jeśli indeks to 0, dodaj na początek
            dodajNaPoczatek(wartosc);
            return;
        }
        Wezel* obecny = poczatek;
        // Przechodzi do węzła na pozycji indeks-1
        for (int i = 0; obecny && i < indeks - 1; i++) {
            obecny = obecny->nastepny;
        }
        if (!obecny) { // Jeśli indeks jest poza końcem listy, dodaj na koniec
            dodajNaKoniec(wartosc);
        }
        else {
            Wezel* nowyWezel = new Wezel(wartosc); // Tworzy nowy węzeł
            nowyWezel->nastepny = obecny->nastepny; // Ustawia wskaźnik następny dla nowego węzła
            nowyWezel->poprzedni = obecny; // Ustawia wskaźnik poprzedni dla nowego węzła
            if (obecny->nastepny) { // Jeśli jest kolejny węzeł
                obecny->nastepny->poprzedni = nowyWezel; // Aktualizuje wskaźnik poprzedni kolejnego węzła
            }
            obecny->nastepny = nowyWezel; // Ustawia wskaźnik następny dla obecnego węzła
            if (obecny == koniec) { // Jeśli nowy węzeł jest na końcu listy
                koniec = nowyWezel; // Aktualizuje wskaźnik końca
            }
        }
    }

    // Metoda usuwająca element z początku listy
    void usunZPoczatku() {
        if (!poczatek) return; // Jeśli lista jest pusta, nic nie robi
        Wezel* temp = poczatek; // Zapamiętuje wskaźnik na początek
        poczatek = poczatek->nastepny; // Przesuwa początek na następny element
        if (poczatek) {
            poczatek->poprzedni = nullptr; // Aktualizuje wskaźnik poprzedni
        }
        else {
            koniec = nullptr; // Jeśli lista była jednoelementowa, ustawia koniec na nullptr
        }
        delete temp; // Usuwa pierwotny początek
    }

    // Metoda usuwająca element z końca listy
    void usunZKonca() {
        if (!koniec) return; // Jeśli lista jest pusta, nic nie robi
        Wezel* temp = koniec; // Zapamiętuje wskaźnik na koniec
        koniec = koniec->poprzedni; // Przesuwa koniec na poprzedni element
        if (koniec) {
            koniec->nastepny = nullptr; // Aktualizuje wskaźnik następny nowego końca
        }
        else {
            poczatek = nullptr; // Jeśli lista była jednoelementowa, ustawia początek na nullptr
        }
        delete temp; // Usuwa pierwotny koniec
    }

    // Metoda usuwająca element z określonego indeksu
    void usunNaIndeksie(int indeks) {
        if (indeks == 0) { // Jeśli indeks to 0, usuń z początku
            usunZPoczatku();
            return;
        }
        Wezel* obecny = poczatek;
        // Przechodzi do węzła na pozycji indeks
        for (int i = 0; obecny && i < indeks; i++) {
            obecny = obecny->nastepny;
        }
        if (!obecny) return; // Jeśli indeks jest poza listą, kończy
        if (obecny->poprzedni) obecny->poprzedni->nastepny = obecny->nastepny; // Aktualizuje wskaźnik następny
        if (obecny->nastepny) obecny->nastepny->poprzedni = obecny->poprzedni; // Aktualizuje wskaźnik poprzedni
        if (obecny == poczatek) poczatek = obecny->nastepny; // Jeśli usuwany jest początek, przesuwa początek
        if (obecny == koniec) koniec = obecny->poprzedni; // Jeśli usuwany jest koniec, przesuwa koniec
        delete obecny; // Usuwa węzeł
    }

    // Metoda wyświetlająca elementy listy od początku
    void wyswietl() const {
        Wezel* obecny = poczatek;
        while (obecny) { // Przechodzi przez listę
            std::cout << obecny->dane << " "; // Wyświetla wartość
            obecny = obecny->nastepny; // Przechodzi do następnego
        }
        std::cout << std::endl;
    }

    // Metoda wyświetlająca elementy listy od końca
    void wyswietlOdKonca() const {
        Wezel* obecny = koniec;
        while (obecny) { // Przechodzi przez listę od końca
            std::cout << obecny->dane << " "; // Wyświetla wartość
            obecny = obecny->poprzedni; // Przechodzi do poprzedniego
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
        std::cout << "3. Dodaj element pod wskazany indeks\n";
        std::cout << "4. Usun element z poczatku listy\n";
        std::cout << "5. Usun element z konca listy\n";
        std::cout << "6. Usun element z pod wskazanego indeksu\n";
        std::cout << "7. Wyswietl cala liste\n";
        std::cout << "8. Wyswietl liste w odwrotnej kolejnosci\n";
        std::cout << "9. Czysc cala liste\n";
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
            std::cout << "Podaj indeks: ";
            std::cin >> indeks;
            std::cout << "Podaj wartosc do dodania: ";
            std::cin >> wartosc;
            lista.dodajNaIndeksie(indeks, wartosc);
            break;
        case 4:
            lista.usunZPoczatku();
            break;
        case 5:
            lista.usunZKonca();
            break;
        case 6:
            std::cout << "Podaj indeks do usuniecia: ";
            std::cin >> indeks;
            lista.usunNaIndeksie(indeks);
            break;
        case 7:
            std::cout << "Lista: ";
            lista.wyswietl();
            break;
        case 8:
            std::cout << "Lista w odwrotnej kolejnosci: ";
            lista.wyswietlOdKonca();
            break;
        case 9:
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