// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1/#

int precedence(char ch){
        if(ch=='^')
            return 3;
        if(ch=='*' || ch=='/')
            return 2;
        if(ch=='+' || ch=='-')
            return 1;
        return 0;
}
    
string infixToPostfix(string token) {
        int n=token.size();
        string res="";
        stack <char> ops;
        for(int i=0;i<n;i++){
            if(token[i]>='a' && token[i]<='z')
                res=res+token[i];
            else if(token[i]=='(')
                ops.push(token[i]);
            else if(token[i]==')'){
                while(!ops.empty() && ops.top()!='('){
                    res=res+ops.top();
                    ops.pop();
                }
                if(!ops.empty())
                    ops.pop();
            }
            else{
                while(!ops.empty() && ops.top()!='(' && precedence(ops.top())>=precedence(token[i])){
                    res=res+ops.top();
                    ops.pop();
                }
                ops.push(token[i]);
            }
        }
        while(!ops.empty()){
            res=res+ops.top();
            ops.pop();
        }
        return res;
}
