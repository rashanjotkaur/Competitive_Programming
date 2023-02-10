// https://leetcode.com/problems/climbing-stairs/description/

// Method 4: DP - Space Optimization
int climbStairs(int n) {
        if(n==1)  return 1;
        int prev2=1;
        int prev1=2;
        for(int i=3;i<=n;i++){
            int curr=prev1 + prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
}


// Method 3: Tabulation - DP
int climbStairs(int n) {
        if(n==1)  return 1;
        vector <int> dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
}


// Method 2: Memoization - While RECURSION, we are storing the values
int climb(vector <int> &dp, int n){
        if(n==1 || n==2)
            return dp[n];
        
        int temp1 = (dp[n-1]!=-1) ? dp[n-1] : climb(dp,n-1);
        int temp2 = (dp[n-2]!=-1) ? dp[n-2] : climb(dp,n-2);
        int temp = temp1 + temp2;
        dp[n] = temp;
        return dp[n];
}
int climbStairs(int n) {
        if(n==1)  return 1;
        vector <int> dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        return climb(dp,n);
}


// Method 1: Recursion - TLE 
int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        return climbStairs(n-1)+climbStairs(n-2);
}
