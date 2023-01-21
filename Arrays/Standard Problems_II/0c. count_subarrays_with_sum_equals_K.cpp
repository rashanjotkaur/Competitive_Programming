// Count Subarrays with Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/description/

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
