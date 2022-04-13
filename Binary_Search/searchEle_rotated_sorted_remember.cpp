// https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int findPivot(vector <int> nums, int low, int high, int key){
        while(low<high){
            int mid=(low+high)/2;
            //for duplicates...
            if(nums[mid]==nums[high])
                high--;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        return high;
    }
    int binarySearch(vector <int> nums, int low, int high, int key){
        int mid=(low+high)/2;
        if(low<=high){
            if(nums[mid]==key)
                return mid;
            else if(nums[mid]<key)
                return binarySearch(nums,mid+1,high,key);
            return binarySearch(nums,low,mid-1,key);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums,0,n-1,target);
        if(pivot==0)
            return binarySearch(nums,0,n-1,target);
        else if(nums[pivot]==target)
            return pivot;
        else if(nums[0]<=target)
            return binarySearch(nums,0,pivot-1,target);
        else
            return binarySearch(nums,pivot,n-1,target);
        return -1;
    }
};
