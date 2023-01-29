// Given a Binary Heap and a new element to be added to this Heap. The task is to insert the new element to the Heap maintaining the properties of Heap. 
// https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/

// Approach: 
// 1. Insert at the end of array --> Increase the size of vector.
// 2. Start from the bottom and move till top --> Bottom to Top --> Use maxHeapify.
#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector <int> &nums, int i, int n){
    if(i<=0)
        return ;
    int parent=(i-1)/2;
    if(nums[parent]<nums[i]){
        swap(nums[parent],nums[i]);
        maxHeapify(nums,parent,n);
    }
}

void insert(vector <int> &nums, int &n, int k){
    n++;
    nums.push_back(k);
    maxHeapify(nums,n-1,n);
}

int main() {
	int n,k,x;
	cin>>n>>k;              // 'k' is the new element to be inserted.
	vector <int> nums;
	for(int i=0;i<n;i++){
	    cin>>x;            //  Already a Max Heap.
	    nums.push_back(x);
	}
	insert(nums,n,k);
	for(int i=0;i<n;i++)
	    cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}
