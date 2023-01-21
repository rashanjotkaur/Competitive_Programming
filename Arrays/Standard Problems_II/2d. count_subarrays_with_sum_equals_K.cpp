// Count Subarrays with Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/description/
// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Method 1: Naive Approach
// Time Complexity: O(N^2)
int subArraySum(int nums[], int n, int k){
        long long currSum=0;
        int count=0;
        for(int i=0;i<n;i++){
            currSum=nums[i];
            for(int j=i+1;j<=n;j++){
                if(currSum==k)
                    count++;
                if(j==n)
                    break;
                currSum+=nums[j];
            }
        }
        return count;
}


// Method 2: Using Hash - Preferred
// Time Complexity: O(N)
int subarraySum(vector <int> &nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map <int,int> ump;
        long long currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum==k)
                count++;
            
            // currSum=x+k 
            // 0----i----j
            //   x    k
            // So, number of times x is present = number of times k is present
            // fre(x)=fre(k);
            // So, store frequency of x in ump as ump[x]++

            long long x=currSum-k;
            if(ump.find(x)!=ump.end())
                count+=ump[x];
            ump[currSum]++;
        }
        return count;
}
