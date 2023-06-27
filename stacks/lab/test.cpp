#include <iostream>
#include "Stack.h"


int main() {


    Stack <int, 5> stack;
    stack.push(1);
    std::cout << stack << "\n";
    stack.push(1);
    std::cout << stack  << "\n";
    stack.push(1);
    std::cout << stack  << "\n";
    stack.push(1);
    std::cout << stack  << "\n"; 
    stack.push(1);
    std::cout << stack  << "\n";
    return 0;
}