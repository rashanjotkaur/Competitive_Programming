// Number of Subsequences That Satisfy the Given Sum Condition
// Problem Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

// Method 2: Using two pointer
// #define mod 1000000007;
int numSubseq(vector <int> &nums, int target) {
        long long mod=1e9+7;
        int n=nums.size();
        vector <int> count(n+1);
        count[0]=1;
        for(int i=1;i<=n;i++)
            count[i]=(count[i-1]*2)%mod;
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        int res=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res=(res+count[r-l])%mod;
                l++;
            }
            else
                r--;
        }
        return res;
}

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

