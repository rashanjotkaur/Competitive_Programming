// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Method 1: Preferred - For explaination check Stiver's Solution
// Func 1:
int search(vector <int> &nums, int target) {
        int idx=binarySearch(nums,0,nums.size()-1,target);
        return idx;
}
// Func 2:
int binarySearch(vector <int> nums, int l, int r, int key){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key)
                return mid;
            if(nums[l]<=nums[mid]){
                if(key>=nums[l] && key<nums[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else{
                if(key>nums[mid] && key<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return -1;
}
  

// Method 2: Finding the pivot.
// Func 1:
int search(vector <int> &nums, int target) {
        int n=nums.size();
        int pivot=findPivot(nums,0,nums.size()-1);
        cout<<pivot<<endl;
        if(nums[pivot]==target)
            return pivot;
        if(pivot==0)
            return binarySearch(nums,0,nums.size()-1,target);
        if(target>=nums[0])
            return binarySearch(nums,0,pivot-1,target);
        return binarySearch(nums,pivot,nums.size()-1,target);
}

// Fun 2:
int findPivot(vector <int> nums, int l, int r){
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else if(nums[mid]<=nums[r])
                r=mid;
        }
        return r;
}

// Fun 3:
int binarySearch(vector <int> nums, int l, int r, int key){
        int mid=(l+r)/2;
        if(l<=r){
            if(nums[mid]==key)
                return mid;
            if(key>nums[mid])
                return binarySearch(nums,mid+1,r,key);
            return binarySearch(nums,l,mid-1,key);
        }
        return -1;
}
    
    
