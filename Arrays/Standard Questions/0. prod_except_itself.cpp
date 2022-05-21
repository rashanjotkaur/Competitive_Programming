// https://leetcode.com/problems/product-of-array-except-self/
// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n=nums.size();
        vector <int> prod(n);
        int temp=1;
        for(int i=0;i<n;i++){
            prod[i]=temp;
            temp=temp*nums[i];
        }
        temp=1;
        for(int i=n-1;i>=0;i--){
            prod[i]=prod[i]*temp;
            temp=temp*nums[i];
        }
        return prod;
    }
};

