// https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/

// Problem Statement: 
// Check if a given array contains duplicate elements within k distance from each other.

// Input:
// testcases=3
// n=6 k=3
// 1 2 3 1 4 5
// 5 3
// 1 2 3 4 5
// 5 3
// 1 2 3 4 4


// Method 1 - Preferred - Using Set
// Approach: 
// 1. We can solve this problem in Θ(n) time using Set. 
// 2. The idea is to add elements to the Set. 
// 3. Remove the elements that are at more than k distance from the current element. 

Create an empty hashtable. 
Traverse all elements from left to right. Let the current element be ‘arr[i]’ 
If the current element ‘arr[i]’ is present in a hashtable, then return true. 
Else add arr[i] to hash and remove arr[i-k] from hash if i is greater than or equal to k
#include <bits/stdc++.h>
using namespace std;

bool duplicateWithinK(vector <int> vec, int k){
    int n=vec.size();
    unordered_set <int> s;
    for(int i=0;i<n;i++){
        if(s.find(vec[i])!=s.end())
            return true;
        s.insert(vec[i]);
        if(i>=k)
            s.erase(vec[i-k]);
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x,k;
	    cin>>n>>k;
	    vector <int> vec;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        vec.push_back(x);
	    }
	    cout<<duplicateWithinK(vec,k)<<endl;
	}
	return 0;
}


// Method 2: Using Map/Hash
bool duplicateWithinK(vector <int> vec, int k){
    int n=vec.size();
    unordered_map <int,int> ump;
    for(int i=0;i<n;i++){
        if(ump[vec[i]])
            return true;
        ump[vec[i]]++;
        if(i>=k)
            ump[vec[i-k]]--;
    }
    return false;
}

// OR

bool duplicateWithinK(vector <int> vec, int k){
    int n=vec.size();
    unordered_map <int,bool> ump;
    for(int i=0;i<n;i++){
        if(ump[vec[i]])
            return true;
        ump[vec[i]]=true;
        if(i>=k)
            ump[vec[i-k]]=false;
    }
    return false;
}


// OR


bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> ump;
        for(int i=0;i<nums.size();i++){
            if(ump[nums[i]]){
                int j=ump[nums[i]];
                j--;
                int diff=abs(i-j);
                if(diff<=k)
                    return true;
            }
            ump[nums[i]]=i+1;
        }
        return false;
}
