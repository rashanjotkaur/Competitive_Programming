// https://leetcode.com/problems/next-greater-element-ii/

// Next Greater Element II
// Here the modification is that array is: Circular
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// Algo:
// So, for last element, we have to find greater element from array[0]----array[n-2]
// So, initally push these elements in stack.
  
  
vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector <int> res(n);
        stack <long long> s;
        for(int i=n-1;i>=0;i--)
            s.push(nums[i]);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            res[i]=s.empty()?-1:s.top();
            s.push(nums[i]);
        }
        return res;
}
