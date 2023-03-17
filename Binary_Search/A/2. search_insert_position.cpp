// Search Insert Position
// https://leetcode.com/problems/search-insert-position/description/

// Method 2: Preferred
// Func 1:
int searchInsert(vector <int> &nums, int target) {
        int idx=-1;
        binarySearch(nums,0,nums.size()-1,target,idx);
        return idx;
}
// Func 2:
void binarySearch(vector <int> nums, int l, int r, int key, int &idx){
        if(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key){
                idx=mid;
                return;
            }
            if(key<nums[mid]){
                idx=mid; 
                binarySearch(nums,l,mid-1,key,idx);
            }
            else{
                idx=mid+1;
                binarySearch(nums,mid+1,r,key,idx);
            }
        }
        return;
}
    

// Method 1:
int binarySearch(vector <int> vec, int l, int r, int target){
        int mid = l + (r-l)/2;
        if(l<r){
            if(vec[mid]==target)
                return mid;
            if(vec[mid]<target)
                return binarySearch(vec, mid+1, r, target);
            else
                return binarySearch(vec, l, mid-1, target);
        }
        if(target<=vec[mid])
            return mid;
        else
            return mid+1;
}
int searchInsert(vector <int> &nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
}



