#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int temp = 0;
        while (x) {
            temp = res*10 + x%10;
            if (temp/10 != res) {
                return 0;
            }
            res = temp;
            x = x/10;
        }
        return res;        
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
   solution_a.reverse(0);

}
