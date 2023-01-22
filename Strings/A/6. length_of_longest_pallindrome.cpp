// https://leetcode.com/problems/longest-palindrome/

// Tricky Remember

class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map <char,int> ump;
        for(int i=0;i<n;i++)
            ump[s[i]]++;
        int len=0;
        for(auto x:ump){
            int fre=x.second; 
            if(fre%2==0)
                len=len+fre;  
            else
                len=len+(fre/2)*2;
        }
        return len<n?len+1:len;
    }
};
