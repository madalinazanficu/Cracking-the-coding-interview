#include <iostream>
#include "./queue_via_stacks.h"
// test for queue vis stacks

int main() {

    My_Queue <int> coada;
    coada.push(1);
    coada.push(2);
    coada.push(3);
    coada.push(4);
    coada.pop();
    coada.pop();
    coada.push(5);
    std::cout << coada << std::endl;

    return 0;
}