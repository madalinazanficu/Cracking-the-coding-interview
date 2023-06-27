class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0;
        while (i < nums1.size() && j < n) {
            if (nums2[j] < nums1[i]) {
                shift(nums1, i);
                nums1[i] = nums2[j];
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (j < n) {
            for (int inx = j; inx < n; inx++) {
                nums1[m + j++] = nums2[inx];
            }
        }
        
        
    }
    void shift(vector<int> &shifted, int index) {
        // the index position remain free for the element to be added
       for (int i = shifted.size() - 1; i > index; i--) {
           shifted[i] = shifted[i - 1];
       }
    }
};