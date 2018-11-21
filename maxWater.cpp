class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        long maxWater = 0, tempWater;
        
        while (start < end) {
            tempWater = (end - start) * min (height[start], height[end]);
            if (maxWater < tempWater) {
                maxWater = tempWater;
            }
            if ( height[start] < height[end]) {
                start ++;
            } else {
                end --;
            }
        }
        
        return maxWater;
    }
};
