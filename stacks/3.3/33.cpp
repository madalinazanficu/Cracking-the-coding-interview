#include <iostream>
#include "stack_of_plates.h"
// for testing stack_of_plates methods


int main() {

    Set_of_Stacks <int, 10> set;

    int n = 16, element = 1;
    for (int i = 0; i < n; ++i) {
        set.push(element);
        element++;
    }

    for (int i = 0; i < set.size(); i++) {
        Stack <int, 10> *st = set.stack_at_index(i);
        std::cout << *st << std::endl;
    }
    

    std:: cout << "test for pop at \n";
    set.pop_at(0);
    std::cout <<"AFTER \n";
    for (int i = 0; i < set.size(); i++) {
        Stack <int, 10> *st = set.stack_at_index(i);
        std::cout << *st << std::endl;
    }


    std::cout <<std::endl;
    // expected 3
    std::cout << set.size() << std::endl;

    set.pop();
    set.pop();
    set.pop();
    set.pop();
    set.pop();

    std::cout <<std::endl;
    // expected 2
    std::cout << set.size() << std::endl;

    set.pop();
    set.pop();
    set.pop();

    std::cout <<std::endl;
    // expected 1
    std::cout << set.size() << std::endl;

    // no pop a the end, but also no memory leaks
    return 0;
}