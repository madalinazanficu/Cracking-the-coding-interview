#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map <int, bool> mymap;
        for (int i = 0; i < nums.size(); ++i) {
            if (mymap.count(nums[i]) == 0) {
                mymap.insert(std::pair<int, bool>(nums[i], 1));
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {

    int n, x;
    std::cin >> n;
    std::vector <int> vect;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        vect.push_back(x);
    }
    Solution my_sol;
    std::cout << my_sol.containsDuplicate(vect);
    return 0;
}