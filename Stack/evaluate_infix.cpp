// https://www.geeksforgeeks.org/expression-evaluation/

#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

int performOperations(int x, int y, char op){
    switch(op){
        case '+': 
            return x + y;
        case '-': 
            return x - y;
        case '*': 
            return x * y;
        case '/': 
            return x / y;
    }
}
// Cases: 
// 1. whitespace
// 2. (
// 3. digit - 0 to 9
// 4. )
// 5. *, /, +, -
int evaluateInfix(string token){
      int n=token.size();
      stack <int> values;
      stack <char> ops; //operators
	
      for(int i=0;i<n;i++){
          if(token[i]==' ')
              continue;

          else if(token[i]=='(')
              ops.push(token[i]);

          else if(isdigit(token[i])){
              int val = 0;
              // There may be more than one digits in number.
              while(i<n && isdigit(token[i])){
                  val = (val*10) + (token[i]-'0');
                  i++;
              }
              values.push(val);
              i--;
          }

          // Closing brace encountered, solve entire brace ().
          else if(token[i]==')'){
              while(!ops.empty() && ops.top()!='('){
                  int y = values.top();
                  values.pop();

                  int x = values.top();
                  values.pop();

                  char op = ops.top();
                  ops.pop();

                  int ans=performOperations(x,y,op);
                  values.push(ans);
              }
              // pop opening brace.
              if(!ops.empty())
                  ops.pop();
          }

          // Current token is an operator.
          else{
              while(!ops.empty() && precedence(ops.top())>= precedence(token[i])){
                int x = values.top();
                values.pop();

                int y = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(performOperations(y, x, op));
              }
              ops.push(token[i]);
          }
      }
	
      while(!ops.empty()){
          int y = values.top();
          values.pop();

          int x = values.top();
          values.pop();

          char op = ops.top();
          ops.pop();

          int ans=performOperations(x, y, op);
          values.push(ans);
      }

      return values.top();
}

int main() {
    cout<<evaluateInfix("10 + 2 * 6")<<endl;
    cout<<evaluateInfix("100 * 2 + 12")<<endl;
    cout<<evaluateInfix("100 * ( 2 + 12 )")<<endl;
    cout<<evaluateInfix("100 * ( 2 + 12 ) / 14")<<endl;
	  return 0;
}


// Input:
// 4
// 10 + 2 * 6
// 100 * 2 + 12
// 100 * ( 2 + 12 )
// 100 * ( 2 + 12 ) / 14

// Output:
// 22
// 212
// 1400
// 100
