#include<vector>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int num1, num2;
        int start, end;
        int nums_size = nums.size();
        int total;
        
        if (nums_size < 4) {
            return results;
        }
        
        sort(nums.begin(), nums.end());
        
        for (num1 = 0; num1 < nums_size -3; num1++) {
            if (nums[num1] + nums[num1+1] + nums[num1+2] + nums[num1+3] > target) break;
            if (nums[num1] + nums[nums_size-3] + nums[nums_size-2] + nums[nums_size-1] < target) continue;
            for (num2 = num1+1; num2 < nums_size - 2; num2 ++) {
                if (nums[num1] + nums[num2] + nums[num2+1] + nums[num1+2] > target) break;
                if (nums[num1] + nums[num2] + nums[nums_size-2] + nums[nums_size-1] < target) continue;
                start = num2 + 1;
                end = nums_size - 1;
                while (start < end) {
                    total = nums[num1] + nums[num2] + nums[start] + nums[end];
                    if (total == target) {
                        results.push_back({nums[num1], nums[num2], nums[start], nums[end]});
                        start ++;
                        end --;
                        while (nums[start] == nums[start - 1] && end > start) start ++;
                        while (nums[end] == nums[end + 1] && end > start) end --;
                    } else if (total < target) {
                        start ++;
                        while (nums[start] == nums[start - 1] && end > start) start ++;
                    } else {
                        end --;                    
                        while (nums[end] == nums[end + 1] && end > start) end --;
                    }
                }
                
                while (nums[num2+1] == nums[num2] && nums_size -2 > num2) num2 ++;
            }
            
            while (nums[num1+1] == nums[num1] && nums_size -3 > num1) num1 ++;
        }
        
        return results;
    }
};
