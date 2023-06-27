#include <iostream>
#include "linked_list.h"

int main() {
    
    LinkedList<int> list;
    list.add_nth_node(0, 1);
    list.add_nth_node(1, 2);
    list.add_nth_node(2, 3);
    list.add_nth_node(3, 4);
    list.rmw_nth_node(2);

    // Node<int> *curr = list.getHead();
    // while (curr != nullptr) {
    //     std::cout << curr->data << " ";
    //     curr = curr->next;
    // }
    // std::cout<<list;

    return 0;
}