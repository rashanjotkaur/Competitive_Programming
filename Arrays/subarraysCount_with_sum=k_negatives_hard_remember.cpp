// https://leetcode.com/problems/subarray-sum-equals-k/
// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1/#


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int currSum=0;
        int count=0;
        unordered_map <int,int> ump;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum==k)
                count++;
            
            //currSum=sum+x;
            //0----i----j
            //  x    sum
            //so, num of times sum is present = num of times x is present
            //fre(sum)=fre(x);
            //So, store frequency of x in ump.
            //ump[x]++
            if(ump.find(currSum-k)!=ump.end()){
                count+=ump[currSum-k];
            }
            ump[currSum]++;
        }
        return count;
    }
};
