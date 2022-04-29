#include <bits/stdc++.h>
using namespace std;

vector <int> nextGreaterEleLeft(vector <int> vec){
    int n=vec.size();
    vector <int> res(n);
    stack <int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=vec[i])
            s.pop();
        res[i]=s.empty()?-1:s.top();
        s.push(vec[i]);
    }
    return res;
}

int main() {
	int t; //testcases
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int x;
	    vector <int> vec;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        vec.push_back(x);
	    }
	    vector <int> res;
	    res=nextGreaterEleLeft(vec);
	    for(int i=0;i<res.size();i++)
	        cout<<res[i]<<" ";
	    cout<<endl;
	}
	return 0;
}

// Input
// 2
// 5
// 40 50 20 10 60
// 6
// 11 6 42 65 32 54
//Output: 
//20 20 10 -1 -1 
//6 -1 32 32 -1 -1

