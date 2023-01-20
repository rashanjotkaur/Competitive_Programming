// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

// Works only for Arrays with Positive Integers.

// It is similar to Kadane Algorithm
// Approach:
// 1. Here, also we will use the sliding window method to find the currSum.
// 2. Then, we will compare it with the given sum.
// 3. If currSum>sum --> then we will decrease it from the starting.

vector<int> subarraySum(vector <int> arr, int n, long long sum){
        long long currSum=0;
        int s=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            while(s<i && currSum>sum){
                currSum=currSum-arr[s];
                s++;
            }
            if(currSum==sum){
                vector <int> res;
                res.push_back(s+1);
                res.push_back(i+1);
                return res;
            }
        }
        vector <int> res;
        res.push_back(-1);
        return res;
}
