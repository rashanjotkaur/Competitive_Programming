// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/#

// Think of the recursive approach 
// Step 1: Base Condition:
//         if(n==0 || W==0)   
//              return 0;
// Step 2: Choice Diagram:
//         if(wt[n-1]<=W)
//              return max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1), knapSack(wt,val,W,n-1));
//         else
//              return knapSack(wt,val,W,n-1);


int knapSack(int W, int wt[], int val[], int n) { 
        int dp[n+1][W+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=W;j++)
            dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j)
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][W];
}
