// Print all the duplicates in the input string
// https://takeuforward.org/data-structure/print-all-the-duplicates-in-the-string/
// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Method 1 - Using HashMap
// Time Complexity: O(nlog(n)), since accessing HashMap takes log(n) time and we access the map for each character in the string (total of n characters).
// Space Complexity: O(1), since the string has only characters from ‘a’ to ‘z’, the size of the HashMap doesn’t exceed 26, irrespective of how big the input string is.

void printDuplicates(string s){
    unordered_map <char,int> ump;
    for(int i=0;i<s.size();i++)
        ump[s[i]]++;
    for(auto x:ump){
        if(x.second>1)
            cout<<x.first<<" "<<x.second<<endl;
    }
}

// Method 2 - Using Vector 
// Approach: 
// 1. Since, the string is going to contain only a – z characters, we don’t even need a HashMap. 
// Instead, we can use an array to store the count values.
void printDuplicates(string s){
    vector <int> fre(26,0);
    for(int i=0;i<s.size();i++)
        fre[s[i]-'a']++;
    for(int i=0;i<26;i++){
        if(fre[i]>1)
            cout<<char(i+'a')<<" "<<fre[i]<<endl;
    }
}
