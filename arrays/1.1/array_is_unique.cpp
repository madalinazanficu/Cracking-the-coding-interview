#include <iostream>
#include <array>
#include <string>

bool is_unique(std::string & my_string)
{
    // in case my string size si bigger than 128
    if (my_string.size() > 128) {
        return false;
    }
    // vector de aparitii
    std::array <bool, 128> char_set;
    for(int i = 0; i < my_string.size(); ++i) {
        int val = my_string.at(i);
        std::cout << "Codul ascii " << val << std::endl;

        if (char_set[val] != 0) {
            return false;
        }
        char_set[val] = true;
    }
    return true;

}

int main() {
    std::string my_string;
    std::cin>> my_string;
    std::cout << "Rezultatul final: " << is_unique(my_string) << std::endl;
    return 0;
}