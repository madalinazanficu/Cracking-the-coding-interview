#include <iostream>
#include <list>
#include <string>

int main () {
    int length1, length2;
    std::cin >> length1 >> length2;
    
    std::list <std::string> words;
    std::list <std::string> more;

    std::string new_word;
    for (int i = 0; i < length1; ++i) {
        std::cin>> new_word;
        words.push_front(new_word);
    }

     for (int i = 0; i < length2; ++i) {
        std::cin>> new_word;
        words.push_front(new_word);
    }

}