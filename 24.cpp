#include <iostream>
#include "linked_list.h"


Node <int> * partitions(Node <int> *node, int x)
{
    Node <int> *start_after = nullptr;
    Node <int> *end_after = nullptr;

    Node <int> *start_before = nullptr;
    Node <int> *end_before = nullptr;

    while (node != nullptr) {

        Node <int> *save = node->next;
        node->next = nullptr;
        if (node->data < x) {

            // primul elem adaugat
            if (start_after == nullptr) {
                start_after = node;
                end_after = node;

            } else {

                end_after->next  = node;
                end_after = node;

            }
        } else {
            
           // primul elem adaugat
            if (start_before == nullptr) {
                start_before = node;
                end_before = node;

            } else {

                end_before->next = node;
                end_before = node;
            }
        }
        node = save;
    }
    end_after->next = start_before;
    return start_after;
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