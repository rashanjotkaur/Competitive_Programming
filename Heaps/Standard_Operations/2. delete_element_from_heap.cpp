// Given a Binary Heap and an element present in the given Heap. The task is to delete an element from this Heap. 
// https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/

// The standard deletion operation on Heap is to delete the element present at the root node of the Heap. That is if it is a Max Heap,
// the standard deletion operation will delete the maximum element and if it is a Min heap, it will delete the minimum element.

// Approach:
// 1. Make the last element, the first element of array --> arr[0]=arr[n-1]
// 2. Decrease the size of array by one 1 --> (n--;)
// 3. Use the maxHeapify function as we use to build the heap, but this time only once. --> Top to Bottom

#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector <int> &nums, int i, int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && nums[left]>nums[largest])
        largest=left;
    if(right<n && nums[right]>nums[largest])
        largest=right;
    if(largest!=i){
        swap(nums[largest],nums[i]);
        maxHeapify(nums,largest,n);
    }
}

void deleteFun(vector <int> &nums, int &n){
    nums[0]=nums[n-1];
    n--;
    nums.pop_back();
    maxHeapify(nums,0,n);
}

int main() {
	int n,x;
	cin>>n;             
	vector <int> nums;
	for(int i=0;i<n;i++){
	    cin>>x;            //  Already a Max Heap.
	    nums.push_back(x);
	}
	deleteFun(nums,n);
	for(int i=0;i<n;i++)
	    cout<<nums[i]<<" ";
	cout<<endl;
	return 0;
}

