// https://leetcode.com/problems/third-maximum-number/

// Here, we used LONG_MIN --> instead of INT_MIN (Remember)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long max1=LONG_MIN;
        long max2=LONG_MIN;
        long max3=LONG_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==max1 || nums[i]==max2 || nums[i]==max3)
                continue;
            if(nums[i]>max1){
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2){
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i]>max3){
                max3=nums[i];
            }
        }
        return max3!=LONG_MIN?max3:max1;
    }
};
