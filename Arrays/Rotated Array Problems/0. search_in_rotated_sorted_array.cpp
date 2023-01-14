// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Func 1: 
int search(vector <int> &nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums,0,n-1);
        cout<<"pivot: "<<pivot<<endl;
        int idx=-1;
        if(pivot==0)
            idx=binarySearch(nums,0,n-1,target);
        else if(nums[pivot]==target)
            idx=pivot;
        else if(nums[0]<=target)
            idx=binarySearch(nums,0,pivot-1,target);
        else
            idx=binarySearch(nums,pivot,n-1,target);
        return idx;
}

// Func 2: Find Pivot: Compare mid with high...
int findPivot(vector <int> nums, int low, int high){
        while(low<high){
            int mid=(low+high)/2;
            // 0 1 2 3 4 5 6
            // 4 5 6 7 0 1 2
            // l=0 r=0 mid=3
            // For Duplicates...
            if(nums[mid]==nums[high])
                high--;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        return high;
}
    
// Func 3: Binary Search
int binarySearch(vector <int> nums, int low, int high, int key){
        int mid=(low+high)/2;
        if(low<=high){
            if(nums[mid]==key)
                return mid;
            if(nums[mid]<key)
                return binarySearch(nums,mid+1,high,key);
            return binarySearch(nums,low,mid-1,key);
        }
        return -1;
}
    
