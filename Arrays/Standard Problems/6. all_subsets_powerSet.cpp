// https://leetcode.com/problems/subsets/

// Recursion and Backtracking

class Solution {
public:
    void solve(vector <int> ip, int i, vector <int> op, vector <vector<int>> &res){
        if(i==ip.size()){
            res.push_back(op);
            return ;
        }
        // Case 1: When we are not including current element ip[i] into op subset, and just 
        // moving to next element --> i+1
        solve(ip,i+1,op,res);
        
        // Case 2: When we are including the current element ip[i] into op subset, and then 
        // moving to next element --> i+1
        op.push_back(ip[i]);
        solve(ip,i+1,op,res);
        op.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector <vector<int>> res;
        if(n==0)
            return res;
        
        vector <int> op;
        solve(nums,0,op,res);
        return res;
    }
};
