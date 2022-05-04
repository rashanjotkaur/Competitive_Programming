// https://practice.geeksforgeeks.org/problems/selection-sort/1/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector <int> &nums, int n){
	for(int i=0;i<n-1;i++){
		int minIdx=i;
		for(int j=i+1;j<n;j++){
			if(nums[j]<nums[minIdx])
				minIdx=j;
		}
		swap(nums[i],nums[minIdx]);
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
		selectionSort(nums,n);
		for(int i=0;i<n;i++)
			cout<<nums[i]<<" ";
	}
	return 0;
}

// Input:
// 1
// 7
// 10 80 30 90 40 50 70
  
// Output:
// 10 30 40 50 70 80 90 
