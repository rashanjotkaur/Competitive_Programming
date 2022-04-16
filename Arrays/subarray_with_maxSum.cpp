// https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm...
// Find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        int max_ending_here=0;
        int max_so_far=INT_MIN;
        
        for(int i=0;i<n;i++){
            max_ending_here+=nums[i];
            if(max_ending_here>max_so_far)
                max_so_far=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }
        
        return max_so_far;
    }
};
