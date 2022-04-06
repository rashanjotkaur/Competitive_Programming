// https://leetcode.com/problems/missing-number/

// Using XOR Operator

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xorVar=0;
        for(int i=1;i<=n;i++)
            xorVar=xorVar^i;
        for(int i=0;i<nums.size();i++)
            xorVar=xorVar^nums[i];
        return xorVar;
    }
};
