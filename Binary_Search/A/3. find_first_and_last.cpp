// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// Hint: We have to use Binary Search Method, two times to find the starting and ending index.

// Method 2:
vector <int> searchRange(vector <int> &nums, int target) {
        vector <int> v;
        v.push_back(-1);
        v.push_back(-1);
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[0]=mid;
               end=mid-1;
           }
           else if(nums[mid]<target)
               st=mid+1;
           else
               end=mid-1;
        }
  
        st=0;
        end=nums.size()-1;
        while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[1]=mid;
               st=mid+1;
           }
           else if(nums[mid]<target)
               st=mid+1;
           else
               end=mid-1;
        }
        return v;
}


// Method 1: 
// Func 1:
vector <int> searchRange(vector <int> &nums, int target) {
        int start=binaryStart(nums,0,nums.size()-1,target);
        int end=binaryEnd(nums,0,nums.size()-1,target);
        vector <int> res;
        res.push_back(start);
        res.push_back(end);
        return res;
}
// Func 2:
int binaryStart(vector <int> nums, int l, int r, int key){
        int mid=(l+r)/2;
        if(l<=r){
            if(key==nums[mid]){
                if(mid==0 || nums[mid-1]!=key)
                    return mid;
                else if(nums[mid-1]==key)
                    return binaryStart(nums,l,mid-1,key); 
            }
            if(key<nums[mid])
                return binaryStart(nums,l,mid-1,key);
            else
                return binaryStart(nums,mid+1,r,key);
        }
        return -1;
}
// Func 3: 
int binaryEnd(vector <int> nums, int l, int r, int key){
        int mid=(l+r)/2;
        if(l<=r){
            if(key==nums[mid]){
                if(mid==nums.size()-1 || nums[mid+1]!=key)
                    return mid;
                else if(nums[mid+1]==key)
                    return binaryEnd(nums,mid+1,r,key); 
            }
            if(key<nums[mid])
                return binaryEnd(nums,l,mid-1,key);
            else
                return binaryEnd(nums,mid+1,r,key);
        }
        return -1;
}
    
    
