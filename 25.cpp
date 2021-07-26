#include <iostream>
#include "linked_list.h"


int sum (LinkedList <int> &l1, LinkedList <int> &l2) {


    Node <int> *node1 = l1.getHead();
    Node <int> *node2 = l2.getHead();

    std::cout << node1->data << " " << node2->data << std::endl;

    int sum, add, carry = 0, nr = 0, p = 1;
    while (node1 != nullptr && node2 != nullptr) {

        sum = node1->data + node2->data + carry;
        add = sum % 10;

        nr = nr + add  * p;
        p = p * 10;

        carry = sum / 10;
        
        node1 = node1->next;
        node2 = node2->next;
    }

    // adaug la nr meu cifrele din l1
    while (node1 != nullptr) {

        sum = carry + node1->data;
        add = sum % 10;

        nr = nr + add * p;
        p = p * 10;

        carry = sum / 10;
        node1 = node1->next;
    }

    // adaug la nr meu cifrele din l2
    while (node2 != nullptr) {

        sum = carry + node2->data;
        add = sum % 10;

        nr = nr + add * p;
        p = p * 10;

        carry = sum / 10;
        node2 = node2-> next;
    }


    // daca am carry 1 la final => mai adaug o cifra in fata
    if (carry != 0) {
        nr = nr + carry * p;
        p = p * 10;
    }
    return nr;
}

int main() {

    int n, m, x;

    std::cin >> n >> m;
    LinkedList <int> l1;
    LinkedList <int> l2;


    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l1.add_nth_node(i, x);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        l2.add_nth_node(i, x);
    }

    std::cout << "Suma \n" << sum(l1, l2);

    return 0;
}