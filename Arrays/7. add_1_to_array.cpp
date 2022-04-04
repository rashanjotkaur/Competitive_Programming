// https://leetcode.com/problems/plus-one/

// Input: digits = [1,2,3] + 1
// Output: [1,2,4]

// Input: digits = [9,9,9] + 1
// Output: [1,0,0,0]

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int r=n-1;
        while(r>=0 && digits[r]==9){
            digits[r]=0;
            r--;
        }
        
        if(r<0)
            digits.insert(digits.begin(),1); //insert 1 at starting
        else
            digits[r]++;
        
        return digits;
    }
};
