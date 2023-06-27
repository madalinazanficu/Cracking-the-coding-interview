#include <iostream>
#include "linked_list.h"
// RECURSIVE APPROACH O(N) SPACE  - because of the stack calls, O(N) TIME

Node <int> * k_last(Node <int> *head, int k, int &i) {
    
    if (head == nullptr) {
        return nullptr;
    }
    Node <int> *node = k_last(head->next, k, i);
    i++;
    if (i == k) {
        return head;
    }
    return node;
} 

int main() {

    LinkedList <int> l;
    int x, n, k, i;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l.add_nth_node(i, x);
    }
    i = 0;
    Node <int> *node = k_last(l.getHead(), k, i);
    std::cout << node->data << std::endl;

}

