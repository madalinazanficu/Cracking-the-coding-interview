#include <iostream>
#include "/home/madalina/cracking/linkedlist/linked_list.h"


int main() {

    int n, x;
    std::cin >> n;

    LinkedList <int> list;
    LinkedList <int> reverse;


    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        list.add_nth_node(i, x);
    }

    int size = list.size();
    Node <int> *node = list.getHead();


    for (int i = 0; i < list.size(); i++) {
        reverse.add_nth_node(size, node->data);

        node = node->next;
    }

    std::cout << list;
    std::cout << reverse;
    return 0;
}