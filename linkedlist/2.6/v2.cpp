#include <iostream>
#include "/home/madalina/cracking/linkedlist/linked_list.h"
#include <stack>
// nu stim cate elemente avem in lista


bool palindrom(LinkedList <int> &list) {

    std::stack <int> st;

    // runner technique
    Node <int> *fast = list.getHead();
    Node <int> *slow = list.getHead();

    while(fast != nullptr && fast->next != nullptr) {

        st.push(slow->data);        
        slow = slow->next;
        fast = fast->next->next;
    }

    // if the fast is on the last element => odd (impar) number of elements
    // fast goes from 2 to 2 => odd number => skip the middle element 
    // there the slow is in the middle

    if (fast != nullptr) {
        slow = slow->next;
    }

    while(slow != nullptr) {
        
        int x = st.top();
        if (x != slow->data) {
            return 0;
        }
        st.pop();
        slow = slow->next;
    }
    if (!st.empty()) {
        return 0;
    }
    return 1;
}


int main() {
    int n, x;
    std::cin >> n;

    LinkedList <int> list;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        list.add_nth_node(i, x);
    }
    std::cout << "Lista este palindrom :" << palindrom(list) << std::endl;

}