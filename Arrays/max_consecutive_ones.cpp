// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                count++;
            else if(nums[i]==0){
                maxCount=max(maxCount,count);
                count=0;
            }
        }
        maxCount=max(maxCount,count);
        return maxCount;
    }
};
