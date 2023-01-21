// https://leetcode.com/problems/rotate-array/

// Method 1: Using O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector <int> res;
        for(int i=n-k;i<n;i++)
            res.push_back(nums[i]);
        for(int i=0;i<n-k;i++)
            res.push_back(nums[i]);
        nums.clear();
        nums=res;
    }
};


// Method 2: Using Reverse Function
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

