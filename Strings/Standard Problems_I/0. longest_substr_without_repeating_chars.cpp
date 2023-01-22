// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// For Explaination: https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/

// Method 1:
// Time Complexity: O(2*N) (sometimes left and right both have to travel complete array)
// Space Complexity: O(1) as maximum elements that can be stored at one time is 26
int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set <char> vis;
        int maxLen=0;
        int start=0;
        for(int i=0;i<n;i++){
            // If duplicate
            while(vis.find(s[i])!=vis.end() && start<i){
                vis.erase(s[start]);
                start++;
            }
            vis.insert(s[i]);
            maxLen=max(maxLen,i-start+1);
        }
        return maxLen;
}


// Method 2: - Preferred - Beautiful Solution
// Time Complexity: O(N)
// Space Complexity: O(1) only 256 are storing. 
int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int start=0;
        int maxLen=0;
        vector <int> pos(256,-1);
        int i=0;
        while(i<n){
            if(pos[s[i]]!=-1)
                start=max(start,pos[s[i]]+1);

            pos[s[i]]=i;
            maxLen=max(maxLen,i-start+1);
            i++;
        }
        return maxLen;
}
