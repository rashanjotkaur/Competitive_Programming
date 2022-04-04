// Maximum Product of Three Numbers
// Find three numbers whose product is maximum.
// https://leetcode.com/problems/maximum-product-of-three-numbers/

// Easy but tricky

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long int proEnd=nums[n-1]*nums[n-2]*nums[n-3];   //product of 3 nums from end.
        cout<<"proEnd "<<proEnd<<endl;
        if(nums[0]<0){
            long long int proStart=nums[0]*nums[1]*nums[n-1];  //product of 3 nums from start.
            cout<<"proStart "<<proStart<<endl;
            return proStart>proEnd?proStart:proEnd;
        }
        return proEnd;
    }
};
