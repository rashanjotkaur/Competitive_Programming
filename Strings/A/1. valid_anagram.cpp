// https://leetcode.com/problems/valid-anagram/description/

// Method - Preferred - Only one time traversal and very less space is  used.
bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        vector <int> fre(26,0);
        for(int i=0;i<s.size();i++){
            fre[s[i]-'a']++;
            fre[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(fre[i]!=0)
                return false;
        }
        return true;
}


// Method 1 - By Sorting - O(nlogn+mlogm)
bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t?true:false;
}

// Method 2: Using two hashmaps
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map <char,int> ump1;
        for(int i=0;i<s.size();i++)
            ump1[s[i]]++;
        unordered_map <char,int> ump2;
        for(int i=0;i<t.size();i++)
            ump2[t[i]]++;
        for(int i=0;i<s.size();i++){
            if(ump1[s[i]]!=ump2[s[i]])
                return false;
        }
        return true;
}

// Method 3: Using on One HashMap - Slowest
bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        unordered_map <char,int> ump;
        for(int i=0;i<s.size();i++)
            ump[s[i]]++;
        
        for(int i=0;i<t.size();i++){
            if(ump[t[i]]!=0)
                ump[t[i]]--;
            if(ump[t[i]]==0){
                ump.erase(t[i]);
            }
        }
        return ump.size()?false:true;
}


// Method 4: Using One HashMap only and one traversal only to increase & decrease the frequency
bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        unordered_map <char,int> ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
            ump[t[i]]--;

        }
        
        for(int i=0;i<s.size();i++){
            if(ump[s[i]]!=0)
                return false;
        }
        return true;
}
