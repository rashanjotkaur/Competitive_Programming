// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/#

// For Positive intergers only.....

// Method 1: O(n^2): here we are checking for sum of all subarrays.
vector <int> subarraySum(vector <int> nums, int n, long long k){
        vector <int> res;
        long long currSum=0;
        for(int i=0;i<n;i++){
            currSum=nums[i];
            for(int j=i+1;j<=n;j++){
                // cout<<currSum<<" ";
                if(currSum==k){
                    res.push_back(i+1);
                    res.push_back(j+1-1);
                    return res;
                }
                if(currSum>k || j==n)
                    break;
                currSum+=nums[j];
            }
            // cout<<endl;
        }
        res.push_back(-1);
        return res;
}

// Method 2: Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: 
// 1. The idea is simple as we know that all the elements in subarray are positive so, If a subarray has sum greater than the given sum then there is no possibility 
//    that adding elements to the current subarray will be equal to the given sum. 
// 2. So the Idea is to use a similar approach to a sliding window. 
//      -> Start with an empty subarray.
//      -> Add elements to the subarray until the sum is less than x( given sum ). 
//      -> If the sum is greater than x, remove elements from the start of the current subarray.

vector <int> subarraySum(vector <int> nums, int n, long long k){
        vector <int> res;
        long long currSum=0;
        int s=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            while(s<i && currSum>k){
                currSum=currSum-nums[s];
                s++;
            }
            if(currSum==k){
                res.push_back(s+1);
                res.push_back(i+1);
                return res;
            }
        }
        res.push_back(-1);
        return res;
}

