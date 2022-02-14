// https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/

// Method 1
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-1-i]);
    }
    cout<<s<<endl;
    return 0;
}

// Method 2
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}