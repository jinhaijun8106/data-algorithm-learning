#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define TEST_MACRO 1 
class Solution {
private:
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> twoIndex;
        for ( int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    twoIndex.push_back(i);
                    twoIndex.push_back(j);
                    return twoIndex;
                }
            }
        }
    }
};

class Solution_B {
public:
    vector <int> twoSum(vector<int>&nums, int target) {
        std::map<int, int> map_value_idx;
        std::map<int, int>::iterator it;
        int find_value;
        vector <int> twoIndex;
        for (int i = 0; i < nums.size(); i++) {
            map_value_idx[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            find_value = target - nums[i];
            it = map_value_idx.find(find_value);
            if (it != map_value_idx.end() && it->second != i) {
                    twoIndex.push_back(i);
                    twoIndex.push_back(it->second);
                    return twoIndex;
                
            }
        }
        
        
    }
};

class Solution_C {
public:
    vector <int> twoSum(vector<int>&nums, int target) {
        map<int, int> map_value_idx;        
        map<int, int>::iterator it;
        int find_value;
        vector <int> twoIndex;

        for (int i = 0; i < nums.size(); i++) {  
            find_value = target - nums[i];           
            it = map_value_idx.find(find_value);     
            if (it != map_value_idx.end()) {
                    twoIndex.push_back(it->second);          
                    twoIndex.push_back(i);                   
                    return twoIndex;
                
            }
            map_value_idx[nums[i]] = i;
        }
        
        
    }
};


int main()
{
   int int_nums[] = {3,3};
   Solution solution_a;
   Solution_B solution_b;
   Solution_C solution_c;
   vector<int> numss (int_nums, int_nums+sizeof(int_nums)/sizeof(int));
   vector<int> result, result_b, result_c;
   int target = 6;
   result = solution_a.twoSum(numss, target);
   cout<<result[0]<<result[1]<<endl;

   result_b = solution_b.twoSum(numss, target);
   cout<<result_b[0]<<result_b[1]<<endl;

   result_c = solution_c.twoSum(numss, target);
   cout<<result_c[0]<<result_c[1]<<endl;
}
