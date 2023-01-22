// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

// Method 2 - Preferred - Beats 100%
string longestCommonPrefix(vector <string> &strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
    
        string first=strs[0];
        string last=strs[n-1];
        int len=min(first.size(),last.size());
        
        string res;
        for(int i=0;i<len;i++){
            if(first[i]==last[i])
                res=res+first[i];
            else
                break;
        }
        return res;
}

// Method 1 - Compare the characters of all strings till characters are same
string longestCommonPrefix(vector <string> &strs) {
        int n=strs.size();
        string comp=strs[0];
        string res;
        int l=0;
        while(l<comp.size()){
            char ch=comp[l];
            bool flag=true;
            for(int i=1;i<n;i++){
                string temp=strs[i];
                if(ch!=temp[l]){
                    flag=false;
                    break;
                }
            }
            if(!flag)
                break;
            res=res+ch;
            l++;
        }
        return res;
}
