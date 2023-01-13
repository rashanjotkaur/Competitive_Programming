// https://leetcode.com/problems/plus-one/

// Input: digits = [1,2,3] + 1
// Output: [1,2,4]

// Input: digits = [9,9,9] + 1
// Output: [1,0,0,0]

// Method 1:
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


// Method 2: By Reversing the Vector
class Solution {
public:
    vector <int> plusOne(vector <int> &digits) {
        int n=digits.size();
        int carry=0;
        reverse(digits.begin(),digits.end());
        digits[0]++;
        if(digits[0]>=10){
            digits[0]%=10;
            carry=1;
        }
        for(int i=1;i<n;i++){
            digits[i]+=carry;
            if(digits[i]>=10){
                digits[i]%=10;
                carry=1;
            }
            else{
                carry=0;
                break;
            }
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
