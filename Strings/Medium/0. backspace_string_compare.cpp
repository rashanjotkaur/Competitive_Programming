// Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/

// Method 2: Using Extra Space - Using the Stack - Preferred
bool backspaceCompare(string s, string t) {
        stack <char> ss,st;
        for(int i=0;i<s.size();i++){
            if(!ss.empty() && s[i]=='#')
                ss.pop();
            else if(s[i]!='#')
                ss.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(!st.empty() && t[i]=='#')
                st.pop();
            else if(t[i]!='#')
                st.push(t[i]);
        }
        if(ss.size()!=st.size())
            return false;
        while(!ss.empty() && !st.empty()){
            if(ss.top()!=st.top())
                return false;
            ss.pop();
            st.pop();    
        }
        return (st.empty() && ss.empty())?true:false;
}

// Method 1: Without using Extra Space
// It takes some more time as compared to using the stack as after erasing the characters from the string, the whole characters on the right side shifts back.
bool backspaceCompare(string s, string t) {
        int i=0,ns=s.size();
        while(i<ns){
            if(i>0 && s[i]=='#'){
                s.erase(i,1);
                s.erase(i-1,1);
                i--;
            }
            else 
                i++;
            ns=s.size();
        }
        i=0;
        while(s[i]=='#')
            s.erase(i,1);
  
        int j=0,nj=t.size();
        while(j<nj){
            if(j>0 && t[j]=='#'){
                t.erase(j,1);
                t.erase(j-1,1);
                j--;
            }
            else 
                j++;
            nj=t.size();
        }
        j=0;
        while(t[j]=='#')    
            t.erase(j,1);
  
        return s==t?true:false;
}
