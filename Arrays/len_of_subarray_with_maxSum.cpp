// C++ program to print length of the largest contiguous array sum
// Kadane's Algorithm
// https://www.geeksforgeeks.org/size-subarray-maximum-sum/

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector <int> nums, int n){
	int max_so_far=INT_MIN;
	int max_ending_here=0;
	int start=0,end=0,s=0;

	for(int i=0;i<n;i++){
		max_ending_here+=nums[i];
		if(max_ending_here>max_so_far){
			max_so_far=max_ending_here;
			start=s;
			end=i;
		}

		if(max_ending_here<0){
			max_ending_here=0;
			s=i+1;
		}
	}
	return end-start+1;
}

int main(){
    int n;
    cin>>n;
    int x;
	vector <int> nums;
	for(int i=0;i<n;i++){
	    cin>>x;
	    nums.push_back(x);
	}
	cout<<maxSubArraySum(nums,n);
	return 0;
}
