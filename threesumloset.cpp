#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret, diffToTarget, curDiffToTarget;
        int check, start, end;
        int tempCompareValue; 
        int nums_size = nums.size();
        int bigger;
        
        if (nums_size <= 2) {
            return -1;
        }
        
        sort(nums.begin(), nums.end());

        /* init value */
        ret = nums[0] + nums[1] + nums[2];
        diffToTarget = ret > target ? (ret - target): (target - ret);
        
        for(check = 0; check < nums_size - 2; check ++){            
            
            start = check + 1;
            end = nums_size - 1;
            while (start < end) {
                curDiffToTarget = nums[check] + nums[start] + nums[end] - target;
                if (curDiffToTarget > 0) {
                    bigger = 1;
                } else {
                    bigger = 0;
                    curDiffToTarget = -curDiffToTarget;
                } 
            
                if (curDiffToTarget < diffToTarget) {
                    cout << check<<start<<end<<curDiffToTarget<<diffToTarget<<endl;
                    diffToTarget = curDiffToTarget;
                    ret = nums[check] + nums[start] + nums[end];
                    if (diffToTarget == 0){
                        return ret;
                    }
                }
            
                if (bigger) {
                    end --;
                    while(nums[end] == nums[end+1] && end > start) end --;
                } else {
                    start ++;
                    while(nums[start] == nums[start-1] && end > start) start ++;
                }
            }
            while (nums[check+1] == nums[check] && check < nums_size - 2) check ++;
        }
        
        return ret;
    }
};

int main()
{
    int inums[] = {1,2,4,8,16,32,64,128};
    vector <int> nums(inums, inums+sizeof(inums)/sizeof(int));
    //vector <string> test = {"", "a"};
    //vector <int> nums = {1,2,4,8,16,32,64,128};
    int target = 82;
    Solution solution_a;
    int output = solution_a.threeSumClosest(nums, target);
    cout << output <<endl;
}
