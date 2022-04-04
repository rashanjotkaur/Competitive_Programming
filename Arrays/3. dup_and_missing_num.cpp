// https://leetcode.com/problems/set-mismatch/
// One of the numbers in array got duplicated to another number in the array, which results in repetition of one number and loss of another number.
// Find the duplicate and missing number.

// Good Question - Medium
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {       
        nums.insert(nums.begin(),0);
        int n=nums.size();
        int dup=-1,mis=-1;
        for(int i=0;i<n;i++){
            while(nums[i]!=i && nums[i]!=nums[nums[i]])
                swap(nums[i],nums[nums[i]]);
            
            if(nums[i]!=i && nums[i]==nums[nums[i]])
                dup=nums[i];
            
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                mis=i;
                break;
            }
        }
        vector <int> res;
        res.push_back(dup);
        res.push_back(mis);
        return res;
    }
};
