#include <iostream>
#include "/home/madalina/cracking/linkedlist/linked_list.h"


void find_duplicates(LinkedList <int> & l)
{
    Node <int> *slow = l.getHead();
    Node <int> *fast;

    int pos_fast = 0, pos_slow = 0;
   
    while (slow != l.getTail()) {

        fast = slow->next;
        pos_fast = pos_slow + 1;

        while(fast != nullptr) {

            if (fast->data == slow->data) {
                Node <int> *save = fast->next;
                l.rmw_nth_node(pos_fast);
                fast = save;

            } else {
                pos_fast++;
                fast = fast->next;
            }
        }
        pos_slow++;
        slow = slow->next;
    }

}

int main () {

    int n, x;
    LinkedList <int> l;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        l.add_nth_node(i, x);
    }
    find_duplicates(l);
    std::cout << "Rezultatul final \n";
    // for (auto it = l.getHead(); it != l.getTail(); it++) {
    //     std::cout << *it << " ";
    // }

    // suprascriere pentru clasa LinkedList
    std::cout << l;
    std::cout << std::endl;
    
}