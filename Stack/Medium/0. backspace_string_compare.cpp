// Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/

// Method : Using Extra Space - Using the Stack - Preferred
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

