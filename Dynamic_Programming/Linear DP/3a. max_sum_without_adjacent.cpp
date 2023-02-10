// Max Sum without Adjacents
// Problem Link: https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1

// Method 4: Tabulation - DP solution with Space Optimization
int findMaxSum(int *arr, int n) {
	    vector <int> dp(n,0);
	    if(n==1)
	        return arr[0];
	    int prev2=arr[0];
	    int prev1=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++){
	        int pick=arr[i]+prev2;
	        int noPick=0+prev1;
	        int curr=max(pick,noPick);
	        prev2=prev1;
	        prev1=curr;
	    }
	    return prev1;
}


// Method 3: Tabulation - DP
int findMaxSum(int *arr, int n) {
	    vector <int> dp(n,0);
	    dp[0]=arr[0];
	    dp[1]=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++){
	        int pick=arr[i]+dp[i-2];
	        int noPick=0+dp[i-1];
	        dp[i]=max(pick,noPick);
	    }
	    return dp[n-1];
}


// Method 2: Memoization - While doing recursion, we are storing the values
int findMax(int arr[], int idx, vector <int> &dp){
	    if(idx==0)
	        return arr[0];
	    if(idx<0)
	        return 0;
	    
	    int pick,noPick;
	    if(idx>=2 && dp[idx-2]!=-1)
	        pick=arr[idx]+dp[idx-2];
	    else
	        pick=arr[idx]+findMax(arr,idx-2,dp);
	    
	    if(idx>=1 && dp[idx-1]!=-1)
	        noPick=dp[idx-1];
	    else
	        noPick=findMax(arr,idx-1,dp);
	    return dp[idx]=max(pick,noPick);
}
int findMaxSum(int *arr, int n) {
	    vector <int> dp(n,-1);
	    return findMax(arr,n-1,dp);
}

// OR 

int findMax(int arr[], int idx, vector <int> &dp){
	    if(idx==0)
	        return arr[0];
	    if(idx<0)
	        return 0;
	    
	    if(dp[idx]!=-1)
	        return dp[idx];
	        
	    int pick=arr[idx]+findMax(arr,idx-2,dp);
	    int noPick=findMax(arr,idx-1,dp);
	    
	    return dp[idx]=max(pick,noPick);
}
int findMaxSum(int *arr, int n) {
    	vector <int> dp(n,-1);
    	return findMax(arr,n-1,dp);
}


// Method 1: Recursion - TLE occurs after 10 cases
int findMax(int arr[], int idx){
	    if(idx==0)
	        return arr[0];
	    if(idx<0)
	        return 0;
	    int pick=arr[idx]+findMax(arr,idx-2);
	    int noPick=findMax(arr,idx-1);
	    return max(pick,noPick);
}
int findMaxSum(int *arr, int n) {
	    return findMax(arr,n-1);
}
