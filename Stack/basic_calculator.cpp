// Basic Calculator 
// Similar to Solving Infix Expression, here only we have addition and subtraction operations.

// Solution with very good explaination
// https://leetcode.com/problems/basic-calculator/discuss/1974370/C%2B%2B-oror-Easy-to-Understand-oror-Stack-oror-Detailed-Explanations

// Question Link:
// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string token) {
        int n=token.size();
        stack <int> s;
        int res=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(token[i]==' ')
                continue;
            if(token[i]=='+')
                sign=1;
            else if(token[i]=='-')
                sign=-1;
            else if(isdigit(token[i])){
                int val=0;
                while(i<n && isdigit(token[i])){
                    val=val*10 + (token[i]-'0');
                    i++;
                }
                i--;
                res=res+(sign*val);
            }
            else if(token[i]=='('){
                s.push(res);
                s.push(sign);
                res=0;
                sign=1;
            }
            else if(token[i]==')'){
                int currSign=s.top();
                s.pop();
                int currRes=s.top();
                s.pop();
                res=currRes+(currSign*res);
            }
        }
        return res;
    }
};
