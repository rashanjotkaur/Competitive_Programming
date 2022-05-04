// https://practice.geeksforgeeks.org/problems/quick-sort/1/#
 
#include <bits/stdc++.h>
using namespace std;

int partition (vector <int> &nums, int low, int high){
	      int pivot=nums[high];
	      int partition_idx=low;
        for(int i=low;i<=high-1;i++){
            if(nums[i]<pivot){
                swap(nums[i],nums[partition_idx]);
                partition_idx++;
            }
        }
        swap(nums[high],nums[partition_idx]);
        return partition_idx;
}    
void quickSort(vector <int> &nums, int low, int high){
        if(low<high){
            int pi=partition(nums,low,high);
            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }
}
int main(){
        int t;
        cin>>t;
        while(t--){
          int n;
          cin>>n;
          vector <int> nums(n);
          for(int i=0;i<n;i++)
            cin>>nums[i];
          quickSort(nums,0,n-1);
          for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
          cout<<endl;
        }
        return 0;
}
  
// Input:
// 2
// 4
// 2 1 3 2
// 6
// 2 1 2 1 6

// Output:
// 1 2 2 3 
// 0 1 1 2 2 6 
