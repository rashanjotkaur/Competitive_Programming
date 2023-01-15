// https://leetcode.com/problems/merge-sorted-array/

// Method 1 - Preferred 
// Time Complexity: O(m+n)
// Space Complexity: O(1)
void merge(vector <int> &nums1, int m, vector <int> &nums2, int n) {
        int i=m-1;
        int j=n-1;
        // last idx: m+n-1 = i+j+1
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[i+j+1]=nums1[i];
                i--;
            }
            else{
                nums1[i+j+1]=nums2[j];
                j--;
            }
        }
        while(j>=0){
            nums1[i+j+1]=nums2[j];
            j--;
        }
}


// Method 2: Using O(m+n) Extra Space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> res;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
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
        for(i=0;i<res.size();i++)
            nums1[i]=res[i];        
}
