// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Method 1 - Preferred
class Solution {
public:
    int removeDuplicates(vector<int>& vec) {
        int n=vec.size();
        int cmp=vec[0];
        int idx=1;
        for(int i=1;i<n;i++){
            if(cmp!=vec[i]){
                cmp=vec[i];
                vec[idx]=cmp;
                idx++;
            }
        }
        return idx;
    }
};


// Method 2:
int removeDuplicates(vector <int> &nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        int i=0;
        int s=0;
        while(i<n && s<n){
            while(i<n && nums[s]==nums[i])
                i++;
            s++;
            if(s<n && i<n)
                nums[s]=nums[i];
        }
        return s;
 }
