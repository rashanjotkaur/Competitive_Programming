
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    stack <int> s;
	    for(int i=n-1;i>=0;i--){
	        if(s.empty())
	            s.push(arr[i]);
	        else if(s.top()<=arr[i])
	            s.push(arr[i]);
	    }
	    while(!s.empty()){
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}