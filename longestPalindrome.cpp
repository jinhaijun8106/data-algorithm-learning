#include <iostream>
using namespace std;
/*
5. Longest Palindromic Substring
*/
class Solution {
public:
    string longestPalindrome(string s){
        int size = s.size();
    }
    string longestPalindrome2(string s) {
        int min_left = 0;
        int maxLen = 0;
        const int s_len = s.length();
        for (int mid = 0; mid < s_len;) {
            if (s_len - mid < maxLen/2) {
                break;
            }
            int left = mid;
            int right = mid;
            while (right < (s_len - 1) && s[right+1] == s[right]) {
                right++;
            }
            mid = right+1;
            
            while (right < (s_len - 1) && left > 0 && (s[right+1] == s[left-1])) {
                right++;
                left--;
            }
            int newLen = right - left + 1;
            if (newLen > maxLen) {
                maxLen = newLen;
                min_left = left;
            }
        
        } /* end of loop mid */
        return s.substr(min_left, maxLen);
    }
        
};


int main()
{
   string s("abcabcbb");
   Solution solution_a;
   string output;

   output = solution_a.longestPalindrome(s);
   cout << output << endl;

}
