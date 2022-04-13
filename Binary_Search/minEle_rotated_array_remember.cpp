// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Binary Search

class Solution {
public:
    int binarySearch(vector <int> nums, int low, int high){
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==nums[high])
                high--;
            else if(nums[mid]>nums[high])
                low=mid+1;
            else if(nums[mid]<nums[high])
                high=mid;
        }
        return nums[low]; 
        // or return nums[right];
        // as low=high
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int pivot=binarySearch(nums,0,n-1);
        return pivot;
    }
};
