// https://practice.geeksforgeeks.org/problems/binary-search/1#

// Method 1: Using Recursion
int binarySearch(int arr[], int low, int high, int key){
        int mid=(low+high)/2;
        if(low<=high){
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                return binarySearch(arr,mid+1,high,key);
            return binarySearch(arr,low,mid-1,key);
        }
        return -1;
}

int binarysearch(int arr[], int n, int k){
        int idx=binarySearch(arr,0,n-1,k);
        return idx;
}



// Method 2: Using While Loop
class Solution{
public:
    int binarySearch(int arr[], int low, int high, int key){
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
    int binarysearch(int arr[], int n, int k){
        int idx=binarySearch(arr,0,n-1,k);
        return idx;
    }
};

