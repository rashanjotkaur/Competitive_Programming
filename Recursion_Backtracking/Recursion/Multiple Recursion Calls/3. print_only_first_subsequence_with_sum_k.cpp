// Print only first subsequence with Sum = k

// Method: Using Recursion - Instead of trying all possible subsequences, we are using bool, so that we can return as soon as we 
// get the first subsequence satisfying the given situation.
#include <bits/stdc++.h>
using namespace std;

bool printSubsequence(int arr[], int i, int n, int currSum, int sum, vector <int> &res){
    if(i==n){
        if(currSum==sum)
            return true;
        return false;
    }
    currSum=currSum+arr[i];
    res.push_back(arr[i]);
    if(printSubsequence(arr,i+1,n,currSum,sum,res))
        return true;
    currSum=currSum-arr[i];
    res.pop_back();
    printSubsequence(arr,i+1,n,currSum,sum,res);
}

int main() {
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector <int> res;
    printSubsequence(arr,0,n,0,target,res);
    for(auto x:res)
        cout<<x<<" ";
    return 0;
}
