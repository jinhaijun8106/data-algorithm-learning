#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hash_char2int;
        map<char, int> ::iterator it;
        int start = -1, end = 0;
        unsigned int maxLen = 0;
        int maxstart = -1;
        
        while (end < s.length()) {
            it = hash_char2int.find(s[end]);

            if (it != hash_char2int.end() &&
                it->second > start) {
                    maxLen = max(maxLen, (unsigned int)(end - start -1 ));
                    start = it->second;
            } 
            
            maxLen = max(maxLen, (unsigned int)(end - start ));
            hash_char2int[s[end]] = end;
            end++;
        }
        return maxLen;
    }
};


class Solution_B {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int  start = -1;
        unsigned int maxLen = 0;
        int i;
        for (i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start) {
                maxLen = max(maxLen, (unsigned int)(i - start - 1));
                start = dict[s[i]];
            }           
            dict[s[i]] = i;
        }

        /* the last substring */
        maxLen = max(maxLen, (unsigned int)(i - start - 1));
        return maxLen;
    }
};

int main()
{
   string s("abcabcbb");
   Solution solution_a;
   int maxLen;

   maxLen = solution_a.lengthOfLongestSubstring(s);
   cout << maxLen << endl;
   Solution_B solution_b;
   maxLen = solution_b.lengthOfLongestSubstring(s);
   cout << maxLen <<endl;

}
