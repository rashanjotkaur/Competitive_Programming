// https://leetcode.com/problems/valid-palindrome/

// Method 1: 
bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z' || (s[i]>='0' && s[i]<='9')))
                str.push_back(tolower(s[i]));
        }
        string revStr=str;
        reverse(revStr.begin(),revStr.end());
        return revStr==str?true:false;
}

// OR //

bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i]))
                str.push_back(tolower(s[i]));
        }
        string revStr=str;
        reverse(revStr.begin(),revStr.end());
        return revStr==str?true:false;
}


// Method 2:
bool isPalindrome(string s) {
        int n=s.size();
        string str;
        for(int i=0;i<n;i++){
            if(isalpha(s[i]) || isdigit(s[i]))
                str.push_back(tolower(s[i]));
        }
        int m=str.size();
        int i=0;
        int j=m-1;
        while(i<=j && i<m && j>=0){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
}


