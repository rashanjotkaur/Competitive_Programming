// Method 1: Using hash -- Unordered_map
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,x;
	    cin>>n;
	    int arr[n];
	    unordered_map <int,int> m;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	    }
	    int maxi=INT_MIN;
	    int flag=0;
	    int ans;
	    for(i=0;i<n;i++){
	       // cout<<m[arr[i]]<<" ";
	        if(m[arr[i]]>maxi){
	            maxi=m[arr[i]];
	            m[arr[i]]=0;
	            ans=arr[i];
	        }
	    }
	    if(maxi>n/2){
	        cout<<ans<<endl;
	    }
	    else{
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}

// Method 2: Moore's Voting Algorithm - Time Complexity: O(n) & Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
int moore_voting(int arr[],int n){
    int count=1;
    int maj_idx=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            count++;
        else
            count--;
        if(count==0){
            maj_idx=i+1;
            count=1;
        }
    }
    return arr[maj_idx];
}
int verify(int arr[],int n,int candidate_key){
    int fre=0;
    for(int i=0;i<n;i++){
	   if(arr[i]==candidate_key){
	       fre++;
	   }
	   if(fre>n/2)
	       return candidate_key;
    }
    return -1;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,x;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int candidate_key=moore_voting(arr,n);
	    cout<<verify(arr,n,candidate_key)<<endl;
	}
	return 0;
}
