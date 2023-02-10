// Problem: In this question, frog is allowed to jump till k indexes
//          i.e i+1, i+2, i+3.....i+k -> We are allowed to jump k indexes. Then what is going to be the minimum energy required.
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

// Input: 
// 3
// 5 3
// 10 20 40 60 30
// 5 3
// 10 20 40 60 80
// 6 2
// 30 10 60 10 60 50

// Output:
// 20
// 70
// 40

#include <bits/stdc++.h>
using namespace std;

int frogJump(vector <int> h, int k){
    int n=h.size();
    vector <int> dp(n,0);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        int j=1;
        int minEne=INT_MAX;
        while(j<=i && j<=k){
            minEne=min(minEne,abs(h[i]-h[i-j])+dp[i-j]);
            j++;
        }
        dp[i]=minEne;
    }
    return dp[n-1];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k,x;
	    cin>>n>>k;
	    vector <int> heights;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        heights.push_back(x);
	    }
	    cout<<"Minimum Energy"<<endl;
	    cout<<frogJump(heights,k)<<endl;
	}
	return 0;
}
