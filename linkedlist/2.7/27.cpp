#include <iostream>
#include <cmath>
#include "/home/madalina/cracking/linkedlist/linked_list.h"


Node <int> *intersection(Node <int> *node1, Node <int> *node2) {

    // verific daca se intersecteaza
    Node <int> *p1 = node1;
    Node <int> *p2 =  node2;

    int size1 = 0, size2 = 0;

    while (p1->next != nullptr) {
        size1++;
        p1 = p1->next;
    }
    size1++;

    while (p2->next != nullptr) {
        size2++;
        p2 = p2->next;
    }
    size2++;

    // daca nu au acelasi tail => nu se intersecteaza
    if (p1 != p2) {
        std::cout << "Nu se intersecteaza!\n";
        return nullptr;
    }

    p1 = node1;
    p2 = node2;

    int diff = size1 - size2;
    if (diff > 0) {
        diff = abs(diff);
        while (diff != 0) {
            p1 = p1->next;
            diff--;
        }
    } else {
        diff = abs(diff);
        while (diff != 0) {
            p2 = p2->next;
            diff--;
        }
    }
    
    while (p1 != nullptr && p2 != nullptr) {
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}


int main() {
    
    LinkedList <int> list;
    LinkedList <int> list2;
    int x, n, m;
    std::cin >> n >> m;

    for(int i = 0; i < n; i++) {
        std::cin >> x;
        list.add_nth_node(i, x);
    }

    for(int i = 0; i < m; i++) {
        std::cin >> x;
        list2.add_nth_node(i, x);
    }

    // 3 noduri
    Node <int> *curr1 = list.getHead();
    int poz = 1;
    while(poz != 0) {
        curr1 = curr1->next;
        poz--;
    }
    poz = 1;
    // leg ultimul la nodul 2
    Node <int> *curr = list2.getHead();
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = curr1;
    // list2.num_elements = list2.num_elements + list.num_elements - 1; schimba pe public num_elements

    std::cout << list;
    std::cout << list2;

    printf("\n");
    Node <int> *node = intersection(list.getHead(), list2.getHead());
   
    std::cout << node->data << "\n";
    return 0;

}