// In case of one array only.
// Maximize this expression: |arr[i]-arr[j]|+|i-j|
// Link: https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/

#include <bits/stdc++.h>
using namespace std;

int check(vector <int> vec){
    int n=vec.size();
    int maxp=INT_MIN;
    int minp=INT_MAX;
    int maxs=INT_MIN;
    int mins=INT_MAX;
    for(int i=0;i<n;i++){
        maxp=max(maxp,vec[i]+i);
        minp=min(minp,vec[i]+i);
        maxs=max(maxs,vec[i]-i);
        mins=min(mins,vec[i]-i);
        cout<<"p: "<<vec[i]+i<<"     s: "<<vec[i]-i<<endl;
    }
    cout<<"maxp: "<<maxp<<"  minp: "<<minp<<"  maxs: "<<maxs<<"  mins: "<<mins<<endl;
    int diffp=abs(maxp-minp);
    int diffs=abs(maxs-mins);
    cout<<"diffp: "<<diffp<<endl;
    cout<<"diffs: "<<diffs<<endl;
    return max(diffp,diffs);
}
int main() {
	int n,x;
	cin>>n;
	vector <int> vec;
	for(int i=0;i<n;i++){
	    cin>>x;
	    vec.push_back(x);
	}
	cout<<check(vec)<<endl;
	return 0;
}

Input:
10
-70 -64 -6 -56 64 61 -57 16 48 -98
