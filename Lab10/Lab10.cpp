#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

struct Osoba {
    string imie;
    string nazwisko;
    string wiek;
    string numer;
    string email;
};

bool Czyjest(string pattern, regex(szukane)) {
    bool error = false;
    if (regex_search(pattern, regex(szukane))) {
        cout << "Znaleziono";
    }
    else {
        cout << "nie znaleziono";
        error == true;
    }
    return error;
}

bool find(int patternlength, string pattern, string word) {
    int length = 0;
    int mem = 0;
    bool next = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == pattern[length]) {
            length++;
            mem = i;
            next = true;
        }
        if (length == patternlength)
            return true;
        if (mem != i) {
            next = false;
            length = 0;
        }
    }
    return false;
}
void zad1() {
    string liczba = "liczba +5.6 liczba -6.31312";
    regex szukane("(\\+)(\\d)(\\.)(\\d)|(\\-)(\\d)(\\.)(\\d)");
    Czyjest(liczba, szukane);
}

void zad2() {
    string godzina = "12:25:43";
    regex szukane("([1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])");
    Czyjest(godzina, szukane);
}

void zad3() {
    string ulica = "Przygodna";
    regex szukanieU("(^[A-Z]{1}[a-z]+)$|(^[A-Z]{1}[a-z]+(\\ )[A-Z]{1}[a-z]+)$");
    Czyjest(ulica, szukanieU);
    cout << " Ulica" << endl;
    string kod = "15-032";
    regex szukanieK("[0-9]{2}-[0-9]{3}");
    Czyjest(kod, szukanieK);
    cout << " kod pocztowy" << endl;
    string numerD = "11D";
    regex szukanieND("(^[1-9]{1}|^[1-9][0-9]|^[1-9])[A-Z]|(^[1-9]{1}|^[1-9][0-9]|^[1-9])$");
    Czyjest(numerD, szukanieND);
    cout << " numer domu" << endl;
    string numerM = "12";
    regex szukanieNM("(^[1-9]{1}|^[1-9][0-9])$");
    Czyjest(numerM, szukanieNM);
    cout << " numer mieszkania" << endl;
}

void WyszukajImie(string imie) {
    regex szukaj("(^[A-Z][a-z]+)$");
    Czyjest(imie, szukaj);
}

void WyszukajNazwisko(string nazwisko) {
    regex szukaj("(^[A-Z][a-z]+)$|(^[A-Z][a-z]+(\\-)[A-z][a-z]+)$");
    Czyjest(nazwisko, szukaj);
}

void WyszukajWiek(string wiek) {
    regex szukaj("[1-9][0-9]$");
    Czyjest(wiek, szukaj);
}
void WyszukaNumer(string numer) {
    regex szukaj("[1-9][0-9]{8}");
    Czyjest(numer, szukaj);
}

void WyszukajEmail(string email) {
    regex szukaj("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    Czyjest(email, szukaj);
}

void zad4() {
    bool error = false;
    string imie, nazwisko, wiek, numer, email;
    cout << "Podaj imie: " << endl;
    cin >> imie;
    cout << "Podaj nazwisko: " << endl;
    cin >> nazwisko;
    cout << "Podaj wiek: " << endl;
    cin >> wiek;
    cout << "Podaj numer telefonu: " << endl;
    cin >> numer;
    cout << "Podaj email: " << endl;
    cin >> email;
    WyszukajImie(imie);
    cout << " imie" << endl;
    WyszukajNazwisko(nazwisko);
    cout << " nazwisko" << endl;
    WyszukajWiek(wiek);
    cout << " wiek" << endl;
    WyszukaNumer(numer);
    cout << " numer telefonu" << endl;
    WyszukajEmail(email);
    cout << " email" << endl;
    Osoba osoba;
    ofstream file;
    file.open("plik.csv", fstream::app);
    if (!error) {
        osoba.imie = imie;
        osoba.nazwisko = nazwisko;
        osoba.wiek = wiek;
        osoba.numer = numer;
        osoba.email = email;
        file << osoba.imie << ";";
        file << osoba.nazwisko << ";";
        file << osoba.wiek << ";";
        file << osoba.numer << ";";
        file << osoba.email << "\n";
    }
    if (error) {
        cout << "Podano zle dane";
    }
    file.close();
}

void zad5() {
    ifstream file;
    string imie, nazwisko, wiek, numer, email;
    Osoba osoba;
    vector<Osoba> osoby;
    file.open("plik.csv");
    while (!file.eof()) {
        getline(file, imie, ';');
        getline(file, nazwisko, ';');
        getline(file, wiek, ';');
        getline(file, numer, ';');
        getline(file, email, '\n');
        osoba.imie = imie;
        osoba.nazwisko = nazwisko;
        osoba.wiek = wiek;
        osoba.numer = numer;
        osoba.email = email;
        osoby.push_back(osoba);
    }

    for (int i = 0; i < osoby.size(); i++) {
        cout << osoby[i].imie << endl;
        cout << osoby[i].nazwisko << endl;
        cout << osoby[i].wiek << endl;
        cout << osoby[i].numer << endl;
        cout << osoby[i].email << endl;
    }

    vector<string> emaile;
    cout << "nazwy unikatowych domen" << endl;
    for (int i = 0; i < osoby.size(); i++) {
        if (find(1, "@", osoby[i].email))
            emaile.push_back(osoby[i].email);
    }
    for (int i = 0; i < emaile.size() - 1; i++) {
        if (emaile[i] != emaile[i + 1])
            cout << emaile[i] << endl;
    }
    int numerT = 0;
    cout << "numery telefonow konczace sie na liczbe parzysta" << endl;
    for (int i = 0; i < osoby.size(); i++) {
        numerT = atoi(osoby[i].numer.c_str());
        if (numerT % 2 == 0)
            cout << numerT << endl;
    }
    cout << "wyswietl osoby o laczonym nazwisku" << endl;
    for (int i = 0; i < osoby.size(); i++) {
        if (find(1, "-", osoby[i].nazwisko))
            cout << osoby[i].nazwisko << endl;
    }
    vector<string> imiona;
    cout << "statystyka imion: " << endl;
    for (int i = 0; i < osoby.size(); i++) {
        imiona.push_back(osoby[i].imie);
    }
    map<string, size_t> map;
    for (auto& i : imiona)
        map[i]++;
    for (auto& j : map)
        cout << j.first << "\t " << j.second << endl;
}

int main() {
    //zad1();
    //zad2();
    //zad3();
    //zad4();
    //zad5();
}
