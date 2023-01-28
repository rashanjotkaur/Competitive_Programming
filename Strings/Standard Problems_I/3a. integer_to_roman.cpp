// Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

string intToRoman(int n) {
        string res;
        vector <string> romans{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector <int> nums{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        int i=12;
        while(n){
            int divisor=n/nums[i];
            n=n%nums[i];
            while(divisor--)
                res=res+romans[i];
            i--;
        }
        return res;
}

