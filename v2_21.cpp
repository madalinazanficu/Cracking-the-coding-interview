#include <iostream>
#include <forward_list>
#include <map>
// lista simplu inlantuita - gresita

void find_duplicates(std::forward_list <int> l)
{
    std::multimap <int, int> m;
    for (std::forward_list <int> ::iterator it = l.begin(); it != l.end(); it++) {
        m.insert(std::make_pair(*it, *it));
    }

    std::forward_list <int> ::iterator prev = l.begin();
    for (auto it = l.begin(); it != l.end() && prev != l.end(); it++) {
        if (m.count(*it) >= 2) {
            m.erase(*it);
            l.erase_after(prev);
        }
        prev++;
    }

    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
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
    
    
}