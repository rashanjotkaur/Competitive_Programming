// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

// Start from j=0 (for(int j=0;j<=sum;j++))

long long mod=1e9+7;
int countAllSubsets(int arr[], int n, int sum){
	    vector <vector<int>> dp(n+1,vector<int>(sum+1,0));
	    for(int i=0;i<=n;i++)
	        dp[i][0]=1;
	    for(int j=1;j<=sum;j++)
	        dp[0][j]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(arr[i-1]<=j)
	                dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	    return dp[n][sum];
	}
