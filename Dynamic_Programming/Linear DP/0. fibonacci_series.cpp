// Fibonacci Series
// https://leetcode.com/problems/fibonacci-number/description/

// Method 4: DP with Space Optimization
int fib(int n) {
        if(n==0)  return 0;
        int prev2=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev1 + prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
}

// Method 3: Tabulation - DP
int fib(int n) {
        if(n==0)  return 0;
        vector <int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
}


// Method 2: Memoization - while RECURSION, we are storing the values
int fibNum(vector <int> &dp, int n){
        if(n==0 || n==1)
            return dp[n];
        
        int temp1 = (dp[n-1]!=-1) ? dp[n-1] : fibNum(dp,n-1);
        int temp2 = (dp[n-2]!=-1) ? dp[n-2] : fibNum(dp,n-2);
        dp[n]=temp1+temp2;
        return dp[n];
}
int fib(int n) {
        if(n==0)  return 0;
        vector <int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return fibNum(dp,n);
}


// Method 1: Using Recursion
int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return fib(n-1)+fib(n-2);
}

