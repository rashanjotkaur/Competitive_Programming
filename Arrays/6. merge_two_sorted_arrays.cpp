// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            for(int i=0;i<n;i++)
                nums1[i]=nums2[i];
            return ;
        }
        if(n==0){
            return ;
        }
        vector <int> res;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                res.push_back(nums2[j]);
                j++;
            }
            else{
                res.push_back(nums1[i]);
                i++;
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            res.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            res.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<m+n;i++)
            nums1[i]=res[i];
    }
};
