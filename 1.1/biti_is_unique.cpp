#include <iostream>
#include <string>

// considering a - z characters
bool is_unique (std::string my_string) {

    // the mask
    int checker = 0;

    for (int i = 0; i < my_string.length(); ++i) {
        // in this way a -> 0, b -> 1, c -> 2 .... 
        int val = my_string.at(i) - 'a';

        // 0000 &
        // 0001 => if the character is a
        // 0000

        if ((checker & (1 << val)) > 0) {
            return false;
        }
        // make that bit 1
        checker = checker | (1 << val);

        // 0000 |
        // 0001
        // 0001
    }
    return true;
}


int main () {
    std::string my_string;
    std::cin>> my_string;
    std::cout << "Rezultatul final: " << is_unique(my_string) << std::endl;
    return 0;
}