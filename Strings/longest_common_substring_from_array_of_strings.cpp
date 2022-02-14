https://www.geeksforgeeks.org/longest-common-substring-array-strings/?ref=rp
#include <bits/stdc++.h>
using namespace std;
void generate_substring(string str,vector <string> &substrings){
    int n=str.size();
    for(int i=0;i<n;i++){
        string s;
        for(int j=i;j<n;j++){
            s=s+str[j];
            substrings.push_back(s);
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector <string> v;
	    string s;
	    for(int i=0;i<n;i++){
	        cin>>s;
	        v.push_back(s);
	    }
	    string str=v[0];
	    vector <string> substrings;
	    generate_substring(str,substrings);
	    string res;
	    for(int i=1;i<n;i++){
	        string x=v[i];
	        for(auto it=substrings.begin();it!=substrings.end();it++){
    	        string y=(*it);
    	        size_t found = x.find(y); 
                if (found != string::npos){ 
    	            if(y.size()>res.size())
    	                res=y;
    	        }
    	    }
	    }
	    cout<<res<<endl;
	    
	}
	return 0;
}
