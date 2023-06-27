#include <iostream>
#include <forward_list>
// lista simplu inlantuita
// O(1) space, O (n ^ 2) time

void find_duplicates(std::forward_list <int> & l)
{
    std::forward_list <int>::iterator p1 = l.begin();
    std::forward_list <int>::iterator p2 = l.begin();
    std::forward_list <int>::iterator prev = l.begin();

    while (p1 != l.end()) {

        p2 = p1;
        prev = p2;
        p2++;

        while (p2 != l.end() && prev != l.end()) {
            if (*p2 == *p1) {
                std::cout << *p2 << "\n";
                l.erase_after(prev);
            }
            prev++;
            p2++;
        }
        p1++;
    }
    
}


int main () {

    int n, x;
    std::forward_list <int> l;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        l.push_front(x);
    }
    find_duplicates(l);
    std::cout << "Rezultatul final \n";
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
}