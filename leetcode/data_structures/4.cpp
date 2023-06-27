class Solution {
public:
     
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0;
        std::vector <int> result;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        if (i < m) {
            for (int it = i; it < m; it++) {
                result.push_back(nums1[it]);
            }
        }
        if (j < n) {
            for (int it = j; it < n; it++) {
                result.push_back(nums2[it]);
            }
        }
        for (int i = 0; i < result.size(); i++) {
            nums1[i] = result[i];
        }
    }
        
};