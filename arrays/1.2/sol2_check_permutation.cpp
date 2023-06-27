// NU merge
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

bool check(std::string str1, std::string str2) {

    if (str1.length() != str2.length()) {
        return false;
    }

    std::multimap<char, int> freq;
    for (char ch : str1) {
        // ascii code
        int order = ch;
        freq.insert(std::make_pair(ch, order));
    }

    for (int i = 0; i < str2.length(); i++) {
        char ch = str2.at(i);

        // nu am gasit caracterul 
        if (freq.find(ch) == freq.end()) {
            return false;
        } else {
            // stergerm fiecare caracter gasit
            freq.erase(ch);
        }
    }
    // verificam daca mai avem caractere ramase
    if (freq.empty() == false) {
        return false;
    }
    return true;
}


int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout<< "Rezultatul final " <<  check(str1, str2) << std::endl;
}