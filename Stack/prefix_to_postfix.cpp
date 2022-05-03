// https://www.geeksforgeeks.org/prefix-postfix-conversion/

#include <bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string token){
    int n=token.size();
    stack <string> s;
    
    for(int i=n-1;i>=0;i--){
        if((token[i]>='a' && token[i]<='z') || (token[i]>='A' && token[i]<='Z') 
        || (token[i]>='0' && token[i]<='9')){
            string temp="";
            temp=temp+token[i];
            s.push(temp);
        }
        else{
            string x=s.top();
            s.pop();
            string y=s.top();
            s.pop();
            string temp="";
            temp=temp+x+y+token[i];
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
	    cout<<prefix_to_postfix(str)<<endl;
	}
	return 0;
}

// Input:
// 2
// *+AB-CD
// *-A/BC-/AKL

// Output:
// AB+CD-*
// ABC/-AK/L-*
