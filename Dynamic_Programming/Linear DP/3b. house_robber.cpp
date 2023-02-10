// House Robber
// https://leetcode.com/problems/house-robber/description/

// Method 1: Tabulation - DP - Space Optimization
int rob(vector <int> &nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+prev2;
            int noPick=0+prev1;
            int curr=max(pick,noPick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
}

// Method 2: Tabulation - DP - Using 1D array
int rob(vector <int> &nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector <int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int pick=nums[i]+dp[i-2];
            int noPick=0+dp[i-1];
            dp[i]=max(pick, noPick);
        }
        return dp[n-1];
}
