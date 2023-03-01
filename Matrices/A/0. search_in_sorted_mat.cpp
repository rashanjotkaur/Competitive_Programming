// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan&id=data-structure-i


// Func 1:
bool searchMatrix(vector <vector<int>>& mat, int target) {
        int targetRow = binarySearch(mat,0,mat.size()-1,target);
        return binarySearchRow(mat[targetRow],0,mat[targetRow].size()-1,target);
}

// Func 2:
int binarySearch(vector <vector<int>> &mat, int l, int r, int key){
        int mid=(l+r)/2;
        if(l<=r){
            if(mat[mid][0]==key)
                return mid;
            else if(mat[mid][0]>key)
                return binarySearch(mat,l,mid-1,key);
            else
                return binarySearch(mat,mid+1,r,key);
        }
        return mid;
}

// Func 3:
bool binarySearchRow(vector <int> nums, int l, int r, int key){
        int mid=(l+r)/2;
        if(l<=r){
            if(nums[mid]==key)
                return true;
            else if(nums[mid]>key)
                return binarySearchRow(nums,l,mid-1,key);
            else
                return binarySearchRow(nums,mid+1,r,key);
        }
        return false;
}
    
    
