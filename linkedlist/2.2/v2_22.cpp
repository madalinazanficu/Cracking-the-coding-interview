#include <iostream>
#include <forward_list>

// non-recursive approach -> O(1) space + O(n) time

void kth_to_last(std::forward_list <int> l, int k) {

    std::forward_list <int> ::iterator fast = l.begin();
    std::forward_list <int> ::iterator slow = l.begin();

    for (int i = 0; i < k; i++) {

        if (fast == l.end()) {
            std::cout <<"Out of bounds\n";
            return;
        }
        fast++;
    }
    while (fast != l.end()) {
        fast++;
        slow++;
    }
    std::cout << "Rezultatul final :\n" << *slow;
}



int main() {

    std::forward_list <int> l;
    int x, n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        l.push_front(x);
    }
    kth_to_last(l, k);
    return 0;
}