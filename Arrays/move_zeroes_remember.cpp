// https://leetcode.com/problems/move-zeroes/

// Use separate variable idx=0, to do inplace movement, without using another vector.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                nums[idx]=nums[i];
                idx++;
            }
        }
        for(int i=0;i<count;i++){
            nums[idx]=0;
            idx++;
        }
    }
};
