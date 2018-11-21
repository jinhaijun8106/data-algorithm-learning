#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> result;
        string dig2chars[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    //vector<string> dig2chars = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
        int dig_size = digits.length();
        if (dig_size == 0) {
            return result;
        }

        result.push_back("");
                               
        for (int i = 0; i < dig_size; i++) {
            vector <string> tmp_result;
            if (digits[i] <= '1' || digits[i] > '9') {
                cout<<1<<endl;
                continue;
            }
            int inum = digits[i] - '0';
            for(int j = 0; j < dig2chars[inum].size();j++){
                if (result.size() == 0) {
                    tmp_result.push_back(" " + dig2chars[inum][j]);
                cout<<2<<tmp_result[0]<<endl;
                    continue;
                }
                for (int k = 0; k < result.size(); k++){
                    tmp_result.push_back(result[k]+dig2chars[inum][j]);
                }
            }
            result.swap(tmp_result);
        }
                               
                cout<<3<<endl;
        return result;
    }
};
int main()
{
    string input("256");
    Solution solution_a;
    vector<string> output = solution_a.letterCombinations(input);
    for (int i = 0; i < output.size(); i++) {
        cout <<output[i]<<endl;
    }
}
