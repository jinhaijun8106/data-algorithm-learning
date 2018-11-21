class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxPreFix;
        int size = strs.size();
        string longestPrefix = "";
        if (size == 0) {
            return longestPrefix;
        }
        maxPreFix = strs[0].size();
        for (int i = 0; i < maxPreFix; i++) { // long first string's each char
            for (int j = 1; j < size; j++){ /* loop each string after 1st char */
                if (strs[j].size() < i || strs[j][i] != strs[0][i]) {
                    return longestPrefix;
                }
            }
            longestPrefix += strs[0][i];
        }
        
        return longestPrefix;
    }
};
