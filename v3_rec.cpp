#include <iostream>
#include "/home/madalina/cracking/linkedlist/linked_list.h"
#include <stack>



Node <int> *solve (Node <int> *first, int len) {

    // numar par de elemente => incepe sa imi returneze din a doua parte a palindromului
    if (len == 0) {
        return first;
    }

    // numar impar de elemente => incepe sa imi returneze din a doua parte a palindromului
    if (len == 1) {
        return first->next;
    }

    // second => apel recursiv pentru a ajunge la a doua parte
    Node <int> *second = solve(first->next, len - 2);


    if (second == nullptr) {
        return nullptr;
    }

    if (second->data != first->data) {
        return nullptr;
    }

    // daca sunt pe ultimul element
    if (second->next == nullptr) {
        return second;
    } else {
        return second->next;
    }
    
}
// 1 2 2 1     first = 1, 2 ; second = 2, 1
// 1 2 1 2 1


int main() {
    int n, x;
    std::cin >> n;

    LinkedList <int> list;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        list.add_nth_node(i, x);
    }

    Node <int> *node = solve(list.getHead(), list.size()); 
    std::cout << "Lista este palindrom :" << std::endl;
    if(node == nullptr) {
        std::cout << "NU\n";
    } else {
        std::cout <<"DA\n";
    }

}
