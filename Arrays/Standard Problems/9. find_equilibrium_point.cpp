// https://leetcode.com/problems/find-pivot-index/

// Method 1: Preferred 
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int pivotIndex(vector <int> &nums) {
        int n=nums.size();
        int leftSum=0;
        int rightSum=0;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        // sum=leftSum+nums[i]+rightSum
        // rightSum=sum-leftSum-nums[i];
        for(int i=0;i<n;i++){
            rightSum=sum-leftSum-nums[i];
            if(leftSum==rightSum)
                return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};

//  OR

class Solution {
public:
    int pivotIndex(vector <int> &nums) {
        int n=nums.size();
        long lSum=0;
        long rSum=0;
        for(int i=0;i<n;i++)
            rSum+=nums[i];
        for(int i=0;i<n;i++){
            rSum=rSum-nums[i];
            if(i!=0)
                lSum=lSum+nums[i-1];
            if(rSum==lSum)
                return i;
        }
        return -1;
    }
};


// Method 2: Using prefix and suffix array
// Time Complexity: O(n)
// Time Complexity: O(n)
class Solution {
public:
    int pivotIndex(vector <int>& nums) {
        int n=nums.size();
        
        vector <int> left(n,0);
        left[0]=nums[0];
        for(int i=1;i<n;i++)
            left[i]=left[i-1]+nums[i];
        
        vector <int> right(n,0);
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            right[i]=right[i+1]+nums[i];
        
        for(int i=0;i<n;i++){
            if(left[i]==right[i])
                return i;
        }
        return -1;
    }
};
