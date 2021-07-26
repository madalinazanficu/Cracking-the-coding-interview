#include <iostream>
#include <cmath>
#include "linked_list.h"



void padding(LinkedList <int> &list, int diff) {

    for (int i = 0; i < diff; i++) {
        list.add_nth_node(0, 0);
    }
}

void make_number(LinkedList <int> &number, Node <int> *node1, Node <int> *node2, int &carry) {


    if (node1 == nullptr && node2 == nullptr) {
        // sunt la final => nu am carry
        carry = 0;
        return;
    }

    // apelare recursiva pana ajung la ultima cifra
    make_number(number, node1->next, node2->next, carry);

    
    // fac suma cifra cu cifra + carry
    int sum = node1->data + node2->data + carry;
    int add = sum % 10;
    carry = sum / 10;

    // adaugare cifra in noul numar pe prima pozitie
    number.add_nth_node(0, add);

}



int main() {

    int n, m, x;
    int carry = 0;

    std::cin >> n >> m;
    LinkedList <int> l1;
    LinkedList <int> l2;
    LinkedList <int> number;


    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l1.add_nth_node(i, x);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        l2.add_nth_node(i, x);
    }

    // daca un numar e mai mare decat altul => in lista nr mai mic => pun zerouri
    int diff = abs(l1.size() - l2.size());
    if (l1.size() > l2.size()) {
        padding(l2, diff);
    } else {
        if (l2.size() > l1.size())
        padding(l1, diff);
    }


    make_number(number, l1.getHead(), l2.getHead(), carry);

    if (carry != 0) {
        number.add_nth_node(0, carry);
    }

    std::cout << "Suma \n";
    std::cout << number;

    return 0;
}