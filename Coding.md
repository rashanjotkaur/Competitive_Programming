# Coding Theory Notes

#### Typedef Keyword
     1. typedef keyword allows the programmer to create new names.
     2. It literally stands for "type definition".
     3. Typedefs can be used both to provide more clarity to your code and to make it easier to make changes to the underlying data types that you use.
     4. For e.g. typedef pair<int,int> pi;
     
#### atoi
     1. The atoi() function takes a string(which represents an integer) as an argument and returns its value of type int. 
     2. So basically the function is used to convert a string argument to an integer.
     3. Syntax:  int temp = atoi(str[i]);
     
#### isdigit(c) 
     1. isdigit() is a function which can be used to check if the passed character is a digit or not. 
     2. It returns a non-zero value if it’s a digit else it returns 0. 
     3. For example, it returns a non-zero value for ‘0’ to ‘9’ and zero for others.
     
#### switch-case
     1. The switch statement evaluates an expression, matching the expression's value to a case clause, and executes statements associated with that case, 
        as well as statements in cases that follow the matching case.
            switch(ch){
                case '*':          //if ch==*
                    s.push(x*y);
                    break;
                case '/':          //if ch==/
                    s.push(x/y);
                    break;
                case '+':          //if ch==+
                    s.push(x+y);
                    break;
                case '-':          //if ch==-
                    s.push(x-y);
                    break;
            }
            
#### cin.ignore()
     1. The cin.ignore() function is used to ignore or clear one or more characters from the input buffer.
     2. Sometimes we need to clear the unwanted buffer, so when next input is taken, it stores into the desired container, but not in the buffer of previous
        variable.
     3. For e.g. Refer to below link
        https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
