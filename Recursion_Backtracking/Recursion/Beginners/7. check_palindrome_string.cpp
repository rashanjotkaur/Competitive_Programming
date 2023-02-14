// Check if string is Palindrome
// https://practice.geeksforgeeks.org/problems/sum-of-digit-is-pallindrome-or-not2751/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s, int l, int r){
    if(l>=r)
        return true;
    if(s[l]!=s[r])
        return false;
    return palindrome(s,l+1,r-1);
}

int main() {
    string s;
    cin>>s;
	cout<<palindrome(s,0,s.size()-1)<<endl;
	return 0;
}
