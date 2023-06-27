#include <iostream>
#include <map>
#include <string>

bool check_pal(std::string str) {
    // asta va fi vectorul de biti
    int bit = 0;

    // iau fiecare litera si ii activez bitul in vector
    for (char ch : str) {
        if (isupper(ch))
            ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') {
            // pt a activa bitul shiftez o masca la stg cu poz lui din alfabet
            int ind = ch - 'a';
            int mask = 1 << ind;
            // verificam daca nu aveam bitul activat oe 1 in vector
            if ((bit & mask) == 0) {
                // actualizam masca punand bitul pe 1 (masca va avea un sg bit 1,
                // acela marcand pozitia din alfabet a literei, restul fiind 0,
                // deci facand | se va schimba doar acel bit)
                bit |= mask;
            } else {
                // daca mai aveam deja o aparitie a acelui caracter, trebuie sa o resetam pe 0
                // negam masca, deci toti bitii vor fi 1 mai putin cel pe care l resetam
                // facem & cu vectorul de biti, deci se va schimba doar bitul pus pe 0
                bit &= ~mask;
            }
        }
    }
    // daca toti bitii sau maxim 1 din ei sunt 0
    if (bit == 0 || (bit & (bit - 1)) == 0)
        return true;
    return false;
}

int main() {

    std::string str;

    std::getline(std::cin, str);
    if (check_pal(str))
        std::cout << "Da\n";
    else
        std::cout << "Nu\n";

    return 0;
}