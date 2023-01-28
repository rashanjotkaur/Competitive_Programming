// https://leetcode.com/problems/roman-to-integer/

// Method 1: Using If Else Conditions only to Map Roman to Integer.
// Func 1:
int romanToInt(string s) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            int currNum=mapToInt(s[i]);
            int nextNum=mapToInt(s[i+1]);
            if(currNum<nextNum)
                res=res-currNum;
            else
                res=res+currNum;
        }
        res=res+mapToInt(s[n-1]);
        return res;
}

// Func 2:
int mapToInt(char ch){
        if(ch=='I')
            return 1;
        if(ch=='V')
            return 5;
        if(ch=='X')
            return 10;
        if(ch=='L')
            return 50;
        if(ch=='C')
            return 100;
        if(ch=='D')
            return 500;
        if(ch=='M')
            return 1000;
        return -1;
}
    
