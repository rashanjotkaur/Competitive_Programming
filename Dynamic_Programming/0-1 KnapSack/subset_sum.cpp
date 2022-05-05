// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

// Base Condition:
// Case 1: if n=0 && sum=0 (there is no element in the array, then it should return true, as we have to make sum=0 also.)
//               return true;
// Case 2: if n=0 && sum=x (there is no element in the array, now we can't make sum=x because we don't have any elements in the array.)
//               return false;
// Case 3: if n=n1 && sum=0 (there are elements in the array, but we have to make sum=0 only, so we'll not include any element from the array.)
//               return true;

// Initialize dp matrix using the above base conditions:
// See from notes:

bool isSubsetSum(vector <int> arr, int sum){
        int n=arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int j=1;j<=sum;j++)
            dp[0][j]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
}
