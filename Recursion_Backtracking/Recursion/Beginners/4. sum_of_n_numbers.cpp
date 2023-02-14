// Find sum of N numbers

// Method 1: Parameterised Recursion
#include <bits/stdc++.h>
using namespace std;

void sumFun(int n,int &sum){
    if(n==0)
        return ;
    sum=sum+n;
    sumFun(n-1,sum);
}

int main() {
    int n;
	cin>>n;
	int sum=0;
	sumFun(n,sum);
	cout<<sum<<endl;
	return 0;
}

// OR

#include <bits/stdc++.h>
using namespace std;

int sumFun(int n,int sum){
    if(n==0)
        return sum;
    return sumFun(n-1,sum+n);
}

int main() {
    int n;
	cin>>n;
	cout<<sumFun(n,0)<<endl;
	return 0;
}


// Method 2: 
#include <bits/stdc++.h>
using namespace std;

int sumFun(int n){
    if(n==0)
        return 0;
    return n+sumFun(n-1);
}

int main() {
    int n;
	cin>>n;
	cout<<sumFun(n)<<endl;
	return 0;
}
