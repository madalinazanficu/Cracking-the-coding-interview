#include <iostream>
#include <string>
#include <algorithm>

bool check(std::string str1, std::string str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    for (int i = 0; i < str1.length(); ++i) {
        if (str1.at(i) != str2.at(i)) {
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