#include <iostream>
#include <map>
#include <string>


int main() {

    std::map <std::string, int> my_map;
    std::multimap <std::string, int> multi;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        my_map.insert(std::make_pair(str, i));
    }

    // Cand avem nevoie de duplicate folosim multimap
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        multi.insert(std::make_pair(str, i));
    }

    std::cout << "Simple Map:\n";
    for(std::map <std::string, int> ::iterator it = my_map.begin(); it != my_map.end(); it++) {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n";

    std::cout << "Multi Map:\n";
    for(std::map <std::string, int> ::iterator it = multi.begin(); it != multi.end(); it++) {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n";

    // Numaram elementele duplicate din multimap
    std::cout << "Count\n";
    for(std::map <std::string, int> ::iterator it = multi.begin(); it != multi.end(); it++) {
        std::cout << multi.count(it->first) << " ";
    }
    std::cout << "\n";



    return 0;
}