// Remove Consecutive Characters
// https://www.geeksforgeeks.org/remove-consecutive-duplicates-string/

// Link - https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
// Similar to Removing Duplicates in Sorted Array

// Method 1 - Simple By Comparing Adjacent elements
string removeConsecutiveCharacter(string s){
        int n=s.size();
        string out="";
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])
                out=out+s[i];
        }
        out=out+s[n-1];
        return out;
}

// Method 2 - Using the comp - As we did in Array for removing duplicates in sorted array
string removeConsecutiveCharacter(string s){
        int n=s.size();
        char comp=s[0];
        int idx=0;
        for(int i=1;i<n;i++){
            if(comp!=s[i]){
                s[idx]=comp;
                idx++;
                comp=s[i];
            }
        }
        s[idx]=comp;
        idx++;
        return s.substr(0,idx);
}

// Method 3: Using Extra string
string removeConsecutiveCharacter(string s){
        int n=s.size();
        string out;
        out.push_back(s[0]);
        int idx=0;
        for(int i=1;i<n;i++){
            if(out[idx]!=s[i]){
                out.push_back(s[i]);
                idx++;
            }
        }
        return out;
}
