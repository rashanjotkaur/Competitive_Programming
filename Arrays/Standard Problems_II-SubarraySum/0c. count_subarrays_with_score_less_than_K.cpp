// Count Subarrays With Score Less Than K
// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long currScore=0;
        long long currSum=0;
        long long count=0;
        int start=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            currScore=currSum*(i-start+1); //Number of elements currently in Subarray: i-start+1
            while(currScore>=k && start<i){
                currSum=currSum-nums[start];
                start++;
                currScore=currSum*(i-start+1);
            }
            if(currScore<k)
                count+=1+(i-start);
        }
        return count;
}
