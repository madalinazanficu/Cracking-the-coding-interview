#include <iostream>
#include "linked_list.h"

// remove a node - not having acces to the whole list
// O(1) TIME AND SPACE

void remove_no_acces(Node <int> *node) {

    // daca e ultimul nod => nu putem face aceasta eliminare
    if (node->next == nullptr) {
        std::cout << "Last node\n";
        return ;
    }

    Node <int> *rmw = node->next;
    // copying the data from the next node
    node->data = rmw->data;

    // deleting the link with the next node
    node->next = rmw->next;

    // free the next node
    delete rmw;
}




int main() {

    int n, x;
    LinkedList <int> l;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l.add_nth_node(i, x);
    }
    Node <int> *node = l.getHead();
    node = node->next;
    node = node->next;
    node = node ->next;

    std::cout << l;
    remove_no_acces(node);
    std::cout << l;
    return 0;
}
