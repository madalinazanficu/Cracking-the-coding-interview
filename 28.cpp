#include <iostream>
#include "/home/madalina/cracking/linkedlist/linked_list.h"

Node<int> *col(LinkedList<int> &ls) {
    
    Node<int> *s, *f;
    // pornim cu pointerii din head
    s = ls.getHead();
    f = ls.getHead();

    // mergem pana se intalnesc sau nu gasim loop
    while (f != nullptr && f->next != nullptr) {
        s = s->next;
        f = f->next->next;
        // daca s au intalnit ne oprim
        if (f == s)
            break;
    }

    // verificam daca avem loop
    if (f == nullptr || f->next == nullptr)
        return nullptr;

    // ne mutam cu un pointer la head dupa ce s au intalnit si mergem
    // pana se intalnesc din nou, atunci vor fi la inceput de loop
    f = ls.getHead();
    while (f != s) {
        f = f->next;
        s = s->next;
    }

    return s;
}

int main() {

    int n, x;
    LinkedList <int> list;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        list.add_nth_node(i, x);
    }

    int poz = 4;
    Node <int> *curr = list.getHead();
    while(poz) {
        curr = curr->next;
        poz--;
    }
    Node <int> *last = curr->next;
    while(last->next != nullptr) {
        last = last->next;
    }

    printf("%d\n", curr->data);
    printf("%d\n", last->data);

    last->next = curr;

    Node<int> *meet = col(list);
    if (meet != nullptr)
        std::cout << meet->data << std::endl;

    return 0;
}
