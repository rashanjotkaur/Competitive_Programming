// Not similar to Rain Water Trapping, that's different.

// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxWater=0;
        while(i<j){
            maxWater=max(maxWater,min(height[i],height[j])*(j-i));
            cout<<maxWater<<" ";
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};
