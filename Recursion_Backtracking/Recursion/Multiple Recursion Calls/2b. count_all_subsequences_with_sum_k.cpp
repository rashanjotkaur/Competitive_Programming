// Count all the subsequences with sum = k
// Striver Video Link: https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7

#include <bits/stdc++.h>
using namespace std;

int countSubsequences(int arr[], int i, int n, int currSum, int sum){
    // For Positive Intergers Only
    if(currSum>sum)
        return 0;
    if(i==n){
        if(currSum==sum)
            return 1;
        return 0;
    }
    currSum=currSum+arr[i];
    int l=countSubsequences(arr,i+1,n,currSum,sum);
    currSum=currSum-arr[i];
    int r=countSubsequences(arr,i+1,n,currSum,sum);
    return l+r;
}

int main() {
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<countSubsequences(arr,0,n,0,target)<<endl;
    return 0;
}
