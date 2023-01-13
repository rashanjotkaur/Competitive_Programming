// https://leetcode.com/problems/contains-duplicate/description/
// All Possible Solutions: https://leetcode.com/problems/contains-duplicate/solutions/2728722/all-possible-easy-solution-with-single-line-code-c/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) 
              return true;
        }
        return false;
    }
};
