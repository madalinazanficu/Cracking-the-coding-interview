#include <vector>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        
        int curr_sum = 0, max_sum = 0, cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {

            // in case all the numbers are negative => max sum will be the maximum mumber from minimums
            if (nums[i] < 0) {
                cnt++;
            }
            curr_sum = curr_sum +  nums[i];

            // in case my sum became smaller than the current number => start a new sequenece
            if (curr_sum < nums[i]) {
                curr_sum = nums[i];
            }

            // check the max sum
            if (curr_sum >= max_sum) {
                max_sum = curr_sum;
            }   
        }
        // in particular search for the max element
        if (cnt == nums.size()) {
            int max_negative = -999999;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > max_negative) {
                    max_negative = nums[i];
                }
            }
            max_sum = max_negative;
        }
        return max_sum;
    }
};