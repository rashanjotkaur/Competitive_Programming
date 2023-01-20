// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Method 1 - Best Approach using Hash Map
// Striver's Best Video to understand the solution: https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=25
// Works for both positive and negative numbers... Even negatives are required in this then only sum will become zero.
// Time Complexity: O(n)
// Space Complexity: O(n)
int maxLen(vector <int> &nums, int n){   
        unordered_map <int,int> ump;
        int maxLen=0;
        int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(prefixSum==0)
                maxLen=max(maxLen,i+1);
            if(ump.find(prefixSum)!=ump.end()){
                int s=ump[prefixSum];
                maxLen=max(maxLen,i-s);
            }
            else
                ump[prefixSum]=i;
        }
        return maxLen;
}


// Method 2: Gives TLE
// Time Complexity: O(N^2) 
// Space Complexity: O(1)
int maxLen(vector <int >&A, int n){   
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += A[j];
                if(sum == 0){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};


// Method 3: Using PrefixSum vector - Gives TLE (351 cases passed out of 405)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Approach: 
// 1. A Naive Approach is to pre-calculate the prefix sum of the array. 
// 2. Then use two nested loops for every starting and ending index and if the prefix sum till the ending index is minus the prefix sum 
//    before the starting index is greater than equal to 0, then update the answer accordingly. 
int maxLen(vector <int> &nums, int n){ 
        int maxLen=0;
        vector <int> prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+nums[i];
        
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(prefixSum[j]==0)
                    maxLen=max(maxLen,j+1);
                if(prefixSum[j]-prefixSum[i]==0)
                    maxLen=max(maxLen,j-i);
                if(j-i<maxLen)
                    break;
            }
        }
        return maxLen;
}
