// Find 'n' factorial

#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1)
        return 1;
    return n*factorial(n-1);
}

int main() {
    int n;
	cin>>n;
	if(n==1)    
	    cout<<1<<endl;
	cout<<factorial(n)<<endl;
	return 0;
}
