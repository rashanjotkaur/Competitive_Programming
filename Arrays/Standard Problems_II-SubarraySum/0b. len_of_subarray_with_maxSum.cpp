// Length of Subarray with Maximum Sum
// https://www.geeksforgeeks.org/size-subarray-maximum-sum/

// Input:
// 2
// 6
// 1 -2 1 1 -2 1
// 8
// -2 -3 4 -1 -2 1 5 -3

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySize(int arr[], int n){
    int currSum=0;
    int maxSum=INT_MIN;
    int s=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
            maxLen=max(maxLen,i-s+1);
        }
        if(currSum<0){
            currSum=0;
            s=i+1;
        }
    }
    return maxLen;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<maxSubArraySize(arr,n)<<endl;
	}
	return 0;
}
