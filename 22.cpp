#include <iostream>
#include "linked_list.h"
// non-recursive approach -> O(1) space + O(n) time

Node <int> * kth_to_last(LinkedList <int> & l, int k)
{
    // taking to pointers to the head of the list
    Node <int> *fast = l.getHead();
    Node <int> *slow = l.getHead();

    for(int i = 0; i < k; ++i) {

        // out of bounds
        if (fast == nullptr) {
            return nullptr; 
        }
        fast = fast->next;
    }
    while(fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


int main() {

    LinkedList <int> l;
    int x, n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l.add_nth_node(i, x);
    }
    Node <int> *node = kth_to_last(l, k);
    if (node != nullptr) {
        std::cout << "Rezultat final :\n" << node->data  << std::endl;
    }
    return 0;
}