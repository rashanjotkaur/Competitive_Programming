//  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

string removeDuplicates(string s) {
        int n=s.size();
        stack <char> st;
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else{
                if(st.top()!=s[i])
                    st.push(s[i]);
                else{
                    while(!st.empty() && st.top()==s[i])
                        st.pop();
                } 
            }
        }
        string out="";
        while(!st.empty()){
            out=st.top()+out;
            st.pop();
        }
        return out;
}
