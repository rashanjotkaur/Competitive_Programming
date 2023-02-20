// Sum of the sums of all possible subsets
// https://www.geeksforgeeks.org/sum-of-the-sums-of-all-possible-subsets/

// Method 2: Best Approach - Tricky
// 1. If we write all the subsequences, a common point of observation is that each number appears 2^(N – 1) times in a subset.
// 2. Hence will lead to the 2^(N-1) as the contribution to the sum. 
// 3. Iterate through the array and add (arr[i] * 2N-1) to the answer. 
#include <bits/stdc++.h>
using namespace std;

long long findSum(int arr[], int n){
    long long sum=0;
    int times=pow(2,n-1);
    for(int i=0;i<n;i++)
        sum=sum+(arr[i]*times);
    return sum;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<findSum(arr,n)<<endl;
    return 0;
}


// Method 1: Using Naive Approach - Finding all the subsets -> then adding the sum of subsets.
#include <bits/stdc++.h>
using namespace std;

void findAllSubsets(int arr[], int i, int n, int sum, vector <int> &subsetSum){
    if(i==n){
        subsetSum.push_back(sum);
        return;
    }
    
    findAllSubsets(arr,i+1,n,sum+arr[i],subsetSum);
    findAllSubsets(arr,i+1,n,sum,subsetSum);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	vector <int> subsetSum;
	findAllSubsets(arr,0,n,0,subsetSum);
	long long sum=0;
	for(auto x:subsetSum)
	    sum+=x;
	cout<<sum<<endl;
	return 0;
}
