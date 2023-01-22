// https://leetcode.com/problems/longest-repeating-character-replacement/

// Method - Using Hashmap - Sliding Window
// Time Complexity: O(n)
int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        int start=0;
        unordered_map <char,int> ump;
        int maxFreCount=0;  // count of characters with max frequency.
        for(int i=0;i<n;i++){
            ump[s[i]]++;
            maxFreCount=max(maxFreCount,ump[s[i]]);
            if(maxFreCount+k < i-start+1){ //Total Num of Elements till now = i-start+1
                ump[s[start]]--;
                start++;
            }
            maxLen=max(maxLen,i-start+1);
        }
        return maxLen;
}
