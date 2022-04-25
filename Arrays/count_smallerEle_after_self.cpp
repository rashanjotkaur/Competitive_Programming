// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Method 1 - O(n*n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector <int> fre(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j])
                    fre[i]++;
            }
        }
        return fre;
    }
};


