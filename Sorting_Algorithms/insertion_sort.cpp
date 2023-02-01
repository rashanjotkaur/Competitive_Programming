// https://practice.geeksforgeeks.org/problems/insertion-sort/1/

// Method 1:
void insertionSort(int arr[], int n){
    for(int j=1;j<n;j++){
        int curr=arr[j];
        int i=j-1;
        while(i>=0 && curr<arr[i]){
            arr[i+1]=arr[i]; // Shift the greater elements by 1 
            i--;
        }
        arr[i+1]=curr;
    }
}


// Method 2:
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector <int> &nums, int n){
      for(int i=1;i<n;i++){
          int key=nums[i];
          int j=i-1;
          while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
          }
          nums[j+1]=key;
      }
}

int main() {
      int t;
      cin>>t;
      while(t--){
          int n;
          cin>>n;
          vector <int> nums(n);
          for(int i=0;i<n;i++)
            cin>>nums[i];
          insertionSort(nums,n);
          for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
          cout<<endl;
      }
      return 0;
}

// Input:
// 1
// 7
// 10 80 30 90 40 50 70
  
// Output:
// 10 30 40 50 70 80 90 
