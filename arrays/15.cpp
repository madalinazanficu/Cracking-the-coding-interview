#include <iostream>
#include <string>

bool check(std::string str_mic, std::string str_mare)
{
    int diff = 0;
    int i = 0, j = 0;
    while (i < str_mare.length() && diff < 2) {
        if (str_mic[j] != str_mare[i]) {
            diff++;
            if (str_mare.length() > str_mic.length()) {
                i++;
            }
        }
        i++;
        j++;
    }
    if (diff >= 2) {
        return false;
    }
    return true;
}

int main () {
    std::string str, str1;
    std::cin >> str>> str1;

    // check the length
    if (str.length() > str1.length() + 1) {
        std::cout << "Nu e corect\n";
        return false;
    }
    if (str1.length() > str.length() + 1) {
        std::cout << "Nu e corect\n";
        return false;
    }
    if (str.length() > str1.length()) {
        std::cout << check(str1, str);
    } else {
        std::cout << check(str, str1);
    }

}