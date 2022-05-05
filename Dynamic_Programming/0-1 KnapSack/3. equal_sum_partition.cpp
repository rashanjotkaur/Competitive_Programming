// https://leetcode.com/problems/partition-equal-subset-sum/
// https://www.geeksforgeeks.org/partition-problem-dp-18/

// Similar to Subset Sum Problem
// Here, We have to divide array into two partitions such that there sum is equal.
// Partition 1 Sum == Partition 2 Sum
// Step 1: Find the sum of array => Sum
// Step 2: If Sum is ODD, then it's not possible. ---> Return FALSE
// Step 3: If Sum is EVEN, then it's possible. ---> Now Check if there exists subset in the array with sum = Sum/2;
//            Hence, this is a Subset Sum Problem.

class Solution {
public:
    bool subsetSum(vector <int> nums, int n, int sum){
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int j=1;j<=sum;j++)
            dp[0][j]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
                
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==0)
            return subsetSum(nums,n,sum/2);
        return false;
    }
};
