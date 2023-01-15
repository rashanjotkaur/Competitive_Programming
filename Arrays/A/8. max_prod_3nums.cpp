// Maximum Product of Three Numbers. Find three numbers whose product is maximum.
// https://leetcode.com/problems/maximum-product-of-three-numbers/

// Easy but tricky

class Solution {
public:
    int maximumProduct(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long prodEnd=nums[n-1]*nums[n-2]*nums[n-3];
        long long prodStart=nums[0]*nums[1]*nums[n-1]; // In case, if the numbers are negative.
        return max(prodStart, prodEnd);
    }
};
