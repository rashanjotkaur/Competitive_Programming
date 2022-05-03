// https://www.geeksforgeeks.org/evaluation-prefix-expressions/

// Using switch-case statements 

#include <bits/stdc++.h>
using namespace std;

double evaluatePrefixExp(string str){
    int n=str.size();
    stack <double> s;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='*' || str[i]=='+' || str[i]=='/' || str[i]=='-'){
            double x=s.top();
            s.pop();
            double y=s.top();
            s.pop();
            switch(str[i]){
                case '*':
                    s.push(x*y);
                    break;
                case '/':
                    s.push(x/y);
                    break;
                case '+':
                    s.push(x+y);
                    break;
                case '-':
                    s.push(x-y);
                    break;
            }
        }
        else{
            int temp=str[i]-'0';
            s.push(temp);
        }
    }
    return s.top();
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string str;
	    cin>>str;   
	    double ans=evaluatePrefixExp(str);
	    cout<<ans<<endl;
    }
	return 0;
}

