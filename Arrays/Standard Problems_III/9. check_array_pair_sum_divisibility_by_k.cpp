// https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/
// Problem: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// 

// Approach:
//      Input: 1 2 3 4 5 10 6 7 8 9 (n=9) (k=5)
//        Rem: 1 2 3 4 0  0 1 2 3 4
// Rem -> Fre: 0 -> 2
//             1 -> 2
//             2 -> 2
//             3 -> 2
//             4 -> 2
// 1. We have two numbers a and b and we want to find (a + b) % k = 0. 
// 2. If (a + b) % k = 0, and a % k = r1 (r1 != 0), b % k = r2 (r2 != 0), then r1 + r2 = k => r1 = k - r2. 
// 3. If r1 occurs one time, r2 also needs to occur one time. 
// 4. Therefore, when the reminder of a number is not equal to zero, occurances of "reminder" has to match occurances of "k - reminder", 
//    so occurances(r1) = occurances(k-r2).

bool canArrange(vector <int> &nums, int k) {
        int n=nums.size();
        if(n%2) 
            return false;
        unordered_map <int,int> fre;
        for(auto x:nums) 
            fre[(x%k + k)%k]++;   //To counter the negatives.
        for(auto x:nums){
            int rem=(x%k + k)%k;
            if(2*rem==k){
                if(fre[rem]%2)
                    return false;  
            } 
            else if(rem==0){ 
                if(fre[rem]%2)
                    return false;   
            }        
            else if(fre[rem]!=fre[k-rem])
                return false;   
        }
        return true;
}

