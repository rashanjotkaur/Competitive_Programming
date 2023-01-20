// https://www.geeksforgeeks.org/longest-sub-array-sum-k/

// Method 1: Using Hash Map - Similar to Largest Sub Array with SUM equal to 0.
int lenOfLongSubarr(int arr[],  int n, int k){ 
        int maxLen=0;
        unordered_map <int,int> ump;
        long long currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(currSum==k)
                maxLen=max(maxLen,i+1);
                
            if(ump.find(currSum)==ump.end())
                ump[currSum]=i;
                
            long long x=currSum-k; // x+k=currSum --> x=currSum-k;
            // Now, we have currSum & k, so if x is present in the ump, it means k was formed.
            if(ump.find(x)!=ump.end())
                maxLen=max(maxLen,i-ump[x]);
        }
        return maxLen;
} 

// Method 2: Naive Solution - Gives TLE - Testcases passed: 189 /193
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int lenOfLongSubarr(int arr[],  int n, int k){ 
        int maxLen=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum=sum+arr[j];
                if(sum==k)
                    maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
} 
