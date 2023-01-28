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
    


// Method 2: Using Hashmap - Unordered Map
// Func 1:
int romanToInt(string s) {
        int n=s.size();
        int res=0;
        unordered_map <char,int> ump;
        mapRomanToInt(ump);
        for(int i=0;i<n-1;i++){
            if(ump[s[i]]<ump[s[i+1]])
                res=res-ump[s[i]];
            else
                res=res+ump[s[i]];
        }
        res=res+ump[s[n-1]];
        return res;
}
// Func 2:
void mapRomanToInt(unordered_map <char,int> &ump){
        ump['I']=1;
        ump['V']=5;
        ump['X']=10;
        ump['L']=50;
        ump['C']=100;
        ump['D']=500;
        ump['M']=1000;
}
