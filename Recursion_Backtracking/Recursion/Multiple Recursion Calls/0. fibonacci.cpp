// Fibonacci Series
// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
        
    return fib(n-1)+fib(n-2);
}

int main() {
    int n;
    cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}


// Note: In case of large 'n' values: #define mod 1000000007; -- will be used.
