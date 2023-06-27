#include <iostream>
#include <string>

bool is_unique(std::string & my_string)
{
    if (my_string.size() > 128) {
        return false;
    }
    bool char_set[128];

    // enhanced for - char by char - but take the ascii code instead
    for (int ch : my_string) {
        if (char_set[ch] != 0) {
            return false;
        }
        char_set[ch] = true;
    }
    return true;
}


int main () {
    std::string my_string;
    std::cin>> my_string;
    std::cout << "Rezultatul final: " << is_unique(my_string) << std::endl;
    return 0;
}