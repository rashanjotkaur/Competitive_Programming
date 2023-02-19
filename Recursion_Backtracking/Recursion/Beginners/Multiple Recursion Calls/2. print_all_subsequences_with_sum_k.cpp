// Find all subsequences with sum equals to K
// https://www.geeksforgeeks.org/find-all-subsequences-with-sum-equals-to-k/


// Testcases
// n k
// 3 3
// 1 2 3
// 6 6
// 17 18 6 11 2 4
// 9 6
// 5 12 3 17 1 18 15 3 17


#include <bits/stdc++.h>
using namespace std;

set <vector<int>> res;

void findAllSubsequences(int arr[],int i, int n, vector <int> out,int currSum, int sum){
    if(i==n){
        if(currSum==sum)
            res.insert(out);
        return;
    }
    currSum=currSum+arr[i];
    out.push_back(arr[i]);
    findAllSubsequences(arr,i+1,n,out,currSum,sum);
    currSum=currSum-arr[i];
    out.pop_back();
    findAllSubsequences(arr,i+1,n,out,currSum,sum);
}

int main() {
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector <int> out;
    int currSum=0;
    findAllSubsequences(arr,0,n,out,currSum,sum);
    for(auto x:res){
        vector <int> temp=x;
        for(auto y:temp)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
