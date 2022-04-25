// https://www.geeksforgeeks.org/merge-sort/
// https://leetcode.com/problems/sort-an-array/

// 1. Like QuickSort, Merge Sort is a Divide and Conquer algorithm. 
// 2. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. 
// 3. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted 
//    and merges the two sorted sub-arrays into one. See the following C implementation for details.

// Algorithm:
// MergeSort(arr[], l,  r)
// If r > l
//      1. Find the middle point to divide the array into two halves:  
//              middle m = l+ (r-l)/2
//      2. Call mergeSort for first half:   
//              Call mergeSort(arr, l, m)
//      3. Call mergeSort for second half:
//              Call mergeSort(arr, m+1, r)
//      4. Merge the two halves sorted in step 2 and 3:
//              Call merge(arr, l, m, r)
               
               
               
class Solution {
public:
    void merge(vector <int> &nums, int l, int mid, int r){
        int n1=mid-l+1;
        int n2=r-mid;    //r-(mid+1)+1
        
        vector <int> a(n1);
        vector <int> b(n2);
        
        for(int i=0;i<n1;i++)
            a[i]=nums[i+l];
        for(int j=0;j<n2;j++)
            b[j]=nums[j+mid+1];
        
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                nums[k]=a[i];
                i++;
                k++;
            }
            else{
                nums[k]=b[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            nums[k]=a[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=b[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector <int> &nums, int l, int r){
        if(r>l){
            int mid = l+(r-l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
