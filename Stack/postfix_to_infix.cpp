// https://www.geeksforgeeks.org/postfix-to-infix/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

string postfix_to_infix(string token){
    int n=token.size();
    stack <string> s;
    
    for(int i=0;i<n;i++){
        if((token[i]>='a' && token[i]<='z') || (token[i]>='A' && token[i]<='Z') 
            || (token[i]>='0' && token[i]<='9')){
            string temp="";
            temp=temp+token[i];
            s.push(temp);
        }
        else{
            string y=s.top();
            s.pop();
            string x=s.top();
            s.pop();
            string temp="";
            temp=temp+"("+x+token[i]+y+")";
            s.push(temp);
        }
    }
    return s.top();
}

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        cout<<postfix_to_infix(str)<<endl;
    }
    return 0;
}

// Input:
// 2
// abc++
// ab*c+

// Output: 
// (a+(b+c))
// ((a*b)+c)
