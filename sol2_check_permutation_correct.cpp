#include <iostream>
#include <string>

bool check(std::string str1, std::string str2)
{
    if(str1.length() != str2.length()) {
        return false;
    }

    int freq[256] = {0};
    for(int ch : str1) {
        freq[ch]++;
    }
    for(int ch : str2) {
        if (freq[ch] == 0) {
            return false;
        }
        freq[ch]--;
    }
    for(int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout<< "Rezultatul final " <<  check(str1, str2) << std::endl;
}