// Happy Number
// https://leetcode.com/problems/happy-number/description/

// Method 2: Using Floyd's Loop Detection Algo(Hare-Tortoise Algo) - Preferred
bool isHappy(int n) {
        int slow=n;
        int fast=findSquare(n);
        while(fast!=1 && fast!=slow){
            fast=findSquare(findSquare(fast));
            slow=findSquare(slow);
        }
        return fast==1?true:false;
}
int findSquare(int n){
        int sum=0;
        while(n){
            sum+=pow(n%10,2);
            n=n/10;
        }
        return sum;
}

// Method 1: Using Unordered_map to detect the loop
    
