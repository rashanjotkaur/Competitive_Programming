//  https://leetcode.com/problems/valid-parentheses/

// Method - Using Stack
bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty())
                st.push(s[i]);
            else{
                if(s[i]==')' && st.top()=='(')
                    st.pop();
                else if(s[i]==']' && st.top()=='[')
                    st.pop();  
                else if(s[i]=='}' && st.top()=='{')
                    st.pop();  
                else 
                    st.push(s[i]);
            }
        }
        return st.empty()?true:false;
}

