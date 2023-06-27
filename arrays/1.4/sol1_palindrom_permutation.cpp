#include <iostream>
#include <map>
#include <string>

bool check(std::string str)
{
    std::multimap<char, int> freq;

    // Case insensitive
    int no_spaces = 0;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (isupper(ch))
                ch = tolower(ch);

            no_spaces++;
            freq.insert(std::make_pair(ch, ch));
        }
    }

    // The string of the length => 1. even => NU! numar impar de aparintii pentru caractere
                            //  => 2. odd (impar) => 1 singur caracter poate avea nr impar de aparitii
    int par;
    if (no_spaces % 2 == 1) {
        par = 0;
    } else {
        par = 1;
    }

    // numarul de caractere cu numar impar de aparitii
    int cnt = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if (freq.count(ch) % 2 == 1) {
            cnt++;
        }
        if (cnt > 1) {
            return false;
        }
    }

    if (par == 1 && cnt > 0) {
        return false;
    }
    if (par == 0 && cnt > 1) {
        return false;
    }
    return true;
}

int main() {

    std::string str;
    std::getline(std::cin, str);
    std::cout << "Rezultatul final \n" << check(str) << std::endl;
}