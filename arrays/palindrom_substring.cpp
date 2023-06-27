class Solution {
public:
    string longestPalindrome(string s) {
        
         int max_len = 0;
         int start = 0, end = 0;
         string result;
        
        // i is considered the center of the palindrom
        for (int i = 0; i < s.length(); i++) {
            
            // secventa cu numar impar de caractere => caracterul din mijloc este palindrom
            int len1 = expand_around_center(s, i, i);
                
            // secventa cu numar par de caractere => avem 2 caractere in mijloc
            int len2 = expand_around_center(s, i, i + 1);
            
            // retinem secventa palindromica maximala
            if (len1 > len2) {
                max_len = len1;
            }
            if (len2 > len1) {
                max_len = len2;
            }
                
            // find start and end of the seq
            // i is considered the middle of the seq
            if (max_len > end - start + 1) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
        for (int i = start; i <= end; i++) {
            result.push_back(s[i]);
        }
        return result;
            
        
    }
    // calculate the length of the palindrom 
    // where left and right are the center of the palindrom
    int expand_around_center(string s, int left, int right) {
        
        int L = left, R = right;
        while(L >= 0 && R <= s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};