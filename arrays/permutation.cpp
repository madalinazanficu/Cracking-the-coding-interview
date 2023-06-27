#include <iostream>
#include <vector>

int main() {

    std::vector<int> nums;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        nums.push_back(x);
    }
    bool ok = true;
    for (int i = 0; i < nums.size(); i++) {
        // verific ca elementul i sa fie pe pozitia i
        if (nums[i] == i + 1) {
            continue;
        } else {
            // fac swap-uri
            while (nums[i] != i + 1) {

                // nu e permutare
                if (nums[i] > nums.size()) {
                    break;
                    ok = false;
                }
                x = nums[nums[i] - 1];
                if (x == nums[i]) {
                    break;
                    ok = false;
                }
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
    }
    std::cout << ok << "\n";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}