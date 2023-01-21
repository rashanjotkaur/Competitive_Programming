// https://leetcode.com/problems/minimum-size-subarray-sum/

// Find the minimal length of a contiguous subarray for which the sum>=target. 
// If there is no such subarray, return 0 instead.


// Method 1 - O(n^2) | Naive Solution | Time Limit Exceeded
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=n;
        bool flag=false;
        for(int i=0;i<n;i++){
            int maxSum=nums[i];
            cout<<maxSum<<" ";
            for(int j=i+1;j<=n;j++){
                if(maxSum>=target){
                    len=min(len,j-i);
                    flag=true;
                }
                if(j==n)
                    break;
                maxSum+=nums[j];
                cout<<maxSum<<" ";
            }
            cout<<endl;
        }
        return flag?len:0;
    }
};

// Method 2 - O(n) | Sliding Window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=n;
        bool flag=false;
        int currSum=0;
        int start=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            cout<<currSum<<" ";
            while(currSum>=target){
                if(currSum>=target){
                    flag=true;
                    len=min(len,i-start+1);
                    cout<<" len: "<<len<<" currSum: "<<currSum<<endl;
                }
                currSum=currSum-nums[start];
                start++;
            }
        }
        return flag?len:0;
    }
};
