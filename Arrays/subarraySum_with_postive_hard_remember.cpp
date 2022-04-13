// Important:
// 1. If negatives integers are also present --- we can use Method 1, but we can't use Method 2 

// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/#

// For Positive intergers only.....

// Method 1: O(n^2): here we are checking for sum of all subsets.
vector<int> subarraySum(int arr[], int n, long long sum){
        int curr_sum, i, j;
        vector <int> res;
        for (i = 0; i < n; i++) {
            curr_sum = arr[i];
            for (j = i + 1; j <= n; j++) {
                if(curr_sum == sum) {
                    // cout<<"i: "<<i<<" j: "<<j-1<<endl;
                    res.push_back(i+1);
                    res.push_back(j-1+1);
                    return res;
                }
                if(curr_sum > sum || j == n)
                    break;
                curr_sum = curr_sum + arr[j];
            }
        }
        res.push_back(-1);
        return res;
}


// Method 2: Efficient Approach: There is an idea if all the elements of the array are positive. If a subarray has sum greater than the given sum then 
// there is no possibility that adding elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window.
// Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the 
// current subarray.

vector<int> subarraySum(int arr[], int n, long long k){
        int curr_sum=arr[0];
        int start=0;
        vector <int> res;
        for(int i=1;i<=n;i++){
            while(curr_sum>k && start<i-1){
                curr_sum=curr_sum-arr[start];
                start++;
            }
            if(curr_sum==k){
                res.push_back(start+1);
                res.push_back(i-1+1);
                return res;
            }
            if(i<n)
                curr_sum=curr_sum+arr[i];
        }
        res.push_back(-1);
        return res;
}
