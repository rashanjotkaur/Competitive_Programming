// Number of Subsequences That Satisfy the Given Sum Condition
// Problem Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

// Method 2: Using two pointer



// Method 1: Using Recursion: Trying all the possible ways to find the sequences.  - Gives TLE
#define mod 1000000007;
void findSubsequences(vector <int> nums, int i, int n, int target, vector <int> out, int &count){
        if(i==n){
            sort(out.begin(),out.end());
            int si=out.size();
            if(si==0)
                return ;
            int tempSum=out[0]+out[si-1];
            if(tempSum<=target){
                count++;
                count=count%mod;
            }
            return ;
        }
        out.push_back(nums[i]);
        findSubsequences(nums,i+1,n,target,out,count);
        out.pop_back();
        findSubsequences(nums,i+1,n,target,out,count);
}
int numSubseq(vector <int> &nums, int target) {
        int n=nums.size();
        int count=0;
        vector <int> out;
        findSubsequences(nums,0,n,target,out,count);
        return count;
}

