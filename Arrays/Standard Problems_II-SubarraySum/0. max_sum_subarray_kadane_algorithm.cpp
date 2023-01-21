// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm
// Initialize:
//    max_so_far = INT_MIN
//    max_ending_here = 0
// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
//    return max_so_far


int maxSubArray(vector <int> &nums) {
        int currSum=0;
        int maxSum=INT_MIN;
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum>maxSum){
                maxSum=currSum;
            }
            if(currSum<0)
                currSum=0;
        }
        return maxSum;
}
