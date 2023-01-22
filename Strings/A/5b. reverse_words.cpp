// https://leetcode.com/problems/reverse-words-in-a-string/
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/#


// Solve on leetocode - As it is difficult
// Method 1 - Using stack - So, we are using space here
string reverseWords(string s) {
        int n=s.size();
        string out;
        string temp="";
        stack <string> st;
        int i=0;
        while(i<n){
            if(s[i]==' '){
                if(temp.size()){
                    st.push(temp);
                    temp="";
                }
            }
            else
                temp=temp+s[i];
            i++;
        }
        if(temp.size())
            st.push(temp);
        while(!st.empty()){
            out=out+st.top();
            if(st.size())
                out=out+" ";
            st.pop();
        }
        return out;
}


// Method 2 - Using temp string
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="";
        string temp="";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(temp.size()){
                    res=res+temp+" ";
                    temp="";
                }
            }
            else
                temp=s[i]+temp;
        }
        if(temp.size()){
            res=res+temp;
            return res;
        }
        if(res[res.size()-1]==' ')
            res.erase(res.size()-1); //res.pop_back();
        return res;
    }
};


// Method 3 - Inplace - Using no extra space
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        while(s[n-1]==' '){
            s.pop_back();
            n--;
        }
        int i=0;
        while(s[i]==' ')
            i++;
        int idx=0;
        while(i<n){
            if(s[i]!=' '){
                s[idx]=s[i];
                idx++;
            }
            else if(i+1<n && s[i]==' ' && s[i+1]!=' '){
                s[idx]=s[i];
                idx++;
            }
            i++;
        }
        s.resize(idx);
        
        reverse(s.begin(),s.end());
        int pivot=0;
        for(int i=0;i<idx;i++){
            if(s[i]==' '){
                reverse(s.begin()+pivot,s.begin()+i);
                pivot=i+1;
            }
        }
        reverse(s.begin()+pivot,s.end());
        return s;
    }
};
