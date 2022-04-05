// https://leetcode.com/problems/array-partition-i/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        sort(nums.begin(),nums.end());
        int i=0;
        long ans=0;
        while(i<n){
            ans+=nums[i];
            i+=2;
        }
        return ans;
    }
};
