// https://leetcode.com/problems/next-permutation/

// Best Approach
void nextPermutation(vector <int> &nums) {
        int n=nums.size();
        int i=n-1;
        while(i>=1){
            if(nums[i-1]<nums[i])
                break;
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
            return ;
        }
        i--;
        int j=n-1;
        while(j>=0 && i>=0){
            if(nums[j]>nums[i])
                break;
            j--;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
}
