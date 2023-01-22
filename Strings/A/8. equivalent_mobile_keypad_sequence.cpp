// Convert a sentence into its equivalent mobile numeric keypad sequence
// Link - https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

// Input
// 2
// GEEKSFORGEEKS
// HELLO WORLD

#include <bits/stdc++.h>
using namespace std;

void mappingFun(unordered_map <char,pair<int,int>> &ump){
    int count=0;
    int button=2;
    char ch;
    for(ch='A';ch<'Z';ch++){
        if(ch=='S'){
            ump[ch]={button,4};
            ch++;
        }
        if(count==3){
            button++;
            count=0;
        }
        count++;
        ump[ch]={button,count};
    }
    ump[ch]={button,4};
    ump[' ']={0,1};
    // for(auto x:ump){
    //     char ch=x.first;
    //     pair <int,int> p=x.second;
    //     cout<<ch<<" "<<p.first<<" "<<p.second<<endl;
    // }
}

int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string s;
	    getline(cin,s);
	    unordered_map <char,pair<int,int>> ump;
	    mappingFun(ump);
	    string res;
	    for(int i=0;i<s.size();i++){
	        pair <int,int> p=ump[s[i]];
	        char ch=p.first+'0';
	        int n=res.size();
	        res.insert(n,p.second,ch);
	    }
	    cout<<res<<endl;
	}
	return 0;
}
