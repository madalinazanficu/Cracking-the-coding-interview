#include <iostream>
#include "animal_shelter.h"
#define NMAX 101

int main() {

    Animal_shelter <animal, NMAX> shelter;
    shelter.enqueue("dog", "Marius");
    shelter.enqueue("dog", "Andrei");
    shelter.enqueue("cat", "Ariana");
    shelter.enqueue("dog", "Laurentiu");
    shelter.enqueue("cat", "Ioana");
    shelter.enqueue("cat", "Maria");
    std::cout << shelter.dequeueAny() << std::endl << shelter.dequeueCat() << std::endl << shelter.dequeueDog() << std::endl;

    return 0;
}


// Marius Andrei Laurentiu
// Ariana Ioana Maria

// Marius - 0  Ariana - 2 Andrei - 1 - expected
// 0 means the oldest