// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> ump;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]]){
                int j=ump[nums[i]];
                j--;
                int diff=abs(i-j);
                if(diff<=k)
                    return true;
            }
            ump[nums[i]]=i+1;
        }
        return false;
    }
};
