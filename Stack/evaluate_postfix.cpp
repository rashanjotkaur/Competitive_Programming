// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector <string> &token) {
        stack <int> s;
        int n=token.size();
        for(int i=0;i<n;i++){
            if(token[i]=="*" || token[i]=="/" || token[i]=="+" || token[i]=="-"){
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                if(token[i]=="*")
                    s.push(y*x);
                else if(token[i]=="/")
                    s.push(y/x);
                else if(token[i]=="-")
                    s.push(y-x);
                else if(token[i]=="+")
                    s.push(y+x);
            }
            else{
                int temp=stoi(token[i]);
                s.push(temp);
            }
        }
        return s.top();
    }
};
