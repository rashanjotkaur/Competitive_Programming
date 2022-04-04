// Method 1: Drawback of this method is that for large value of n overflow will occur, since we are doing n^2
#include <bits/stdc++.h> 
using namespace std; 

int getMissingNo(int arr[],int n){ 
	int total = (n)*(n + 1)/2; 
	for (int i=0;i<n-1;i++) 
		total -= arr[i]; 
	return total; 
} 
// Driver Code
int main(){ 
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n-1;i++){
	        cin>>arr[i];
	    }
	    cout<<getMissingNo(arr,n)<<endl;
	}
} 

// Method 2: XOR
#include <bits/stdc++.h> 
using namespace std; 

// Driver Code
int main(){ 
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    long long int x=0;
	    for(i=0;i<n-1;i++){
	        cin>>arr[i];
	        x=x^arr[i];
	    }
	    for(int i=1;i<=n;i++){
	    	x=x^i;
	    }
	    cout<<x<<endl;
	}
} 

// Method 3: The BEST APPROACH
#include <bits/stdc++.h> 
using namespace std; 

int getMissingNo(int arr[],int n){ 
	int total=1;
	for(int i=2;i<=n;i++){
		total=total+i;
		total=total-arr[i-2];
	} 
	return total;
} 
// Driver Code
int main(){ 
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n-1;i++){
	        cin>>arr[i];
	    }
	    cout<<getMissingNo(arr,n)<<endl;
	}
} 
