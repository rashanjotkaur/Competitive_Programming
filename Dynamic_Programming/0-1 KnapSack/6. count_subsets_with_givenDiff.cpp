// https://github.com/TesseractCoding/NeoAlgo/blob/master/C-Plus-Plus/dp/subsets_with_given_diff.cpp

// s1+s2=sum
// s1-s2=diff
// Subtract above 2 equations
// 2s2=sum-diff
// s2=(sum-diff)/2
// Now, here we have find the number of subsets with SUM=s2
// So, similar to Que 4

// Count subsets with given difference
#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithGivenSum(vector <int> nums, int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
      dp[i][0]=1;
    for(int j=1;j<=sum;j++)
      dp[0][j]=0;
    for(int i=1;i<=n;i++){
      for(int j=0;j<=sum;j++){
        if(nums[i-1]<=j)
          dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
        else
          dp[i][j]=dp[i-1][j];
      }
    }
    return dp[n][sum];
}

int countSubsets(vector <int> nums, int n, int diff){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=nums[i];
    int twice_s2=sum-diff;
    //since, we have to divide twice_s2/2, if it is odd, then its not possible
    if(twice_s2%2==1 || twice_s2<0) 
        return 0;
    int s2=twice_s2/2;
    return countSubsetsWithGivenSum(nums,n,s2);
}

int main() {
    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0;i<n;i++)
      cin>>nums[i];
    int diff;
    cin>>diff;
    cout<<countSubsets(nums,n,diff)<<endl;
    return 0;
}
