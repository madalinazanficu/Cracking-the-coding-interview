#include <iostream>
#include <unordered_map>
#include <string>


int main() {

    std::unordered_map <std::string, int> hash;
    std::unordered_multimap<std::string, int> multihash;


    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;

        hash.insert(std::make_pair(str, i));
        multihash.insert(std::make_pair(str, i));
    }

    // Counting will be 0 or 1 in the case of the unordered_map
    std::cout << "\nCount for unordered_map:\n";
    for (std::unordered_map <std::string, int> ::iterator it = hash.begin(); it != hash.end(); it++) {
        std::cout << hash.count(it->first) << " ";
    }
    std::cout << '\n';

    std::cout << "Count for unordered_multimap:\n";
    for (std::unordered_map <std::string, int> ::iterator it = multihash.begin(); it != multihash.end(); it++) {
        if (multihash.count(it->first) == 1) {
            std::cout << it->first << " ";
        }
    }
    std::cout << '\n';

    return 0;
}