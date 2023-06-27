#include <iostream>
#include "linked_list.h"


Node <int> * partitions(Node <int> * node, int k) {

    Node <int> *head = node;
    Node <int> *tail = node;

    while(node != nullptr) {

        Node <int> *save = node->next;

        if (node->data < k) {
            // adaugare la inceput
            node->next = head;
            head = node;
        } else {

            // adaugare la final
            tail->next = node;
            tail = node;
        }
        node = save;
    }
    tail->next = nullptr;
    return head;
}


int main() {

    int n, x, k;
    LinkedList <int> l;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l.add_nth_node(i, x);
    }
    Node <int> *node = partitions(l.getHead(), k);
    while(node != nullptr) {
        std::cout << node->data << " ";
        node = node ->next;
    }


    return 0;
}