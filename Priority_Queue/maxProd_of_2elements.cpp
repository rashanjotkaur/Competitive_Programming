// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector <int> &nums) {
        int n=nums.size();
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>2)
                pq.pop();
        }
        int x=pq.top()-1;
        pq.pop();
        int y=pq.top()-1;
        pq.pop();
        return x*y;
    }
};
