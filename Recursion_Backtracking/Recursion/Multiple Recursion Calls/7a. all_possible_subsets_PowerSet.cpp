// Find all possible Subsets - Find the Power Set
// Problem Link: https://leetcode.com/problems/subsets/

// Method 2: Using Iterative Approach 
// Advantage of Using Iterative Approach: 
// 1. If the array is sorted then, using this approach subsets will stored in vector in sorted manner.
// 2. We don't have to sort the res - vector.
// Func 1:
vector <vector<int>> subsets(vector <int> &nums) {
        int n=nums.size();
        vector <vector<int>> res;
        vector <int> op;
        findPowerSet(nums,0,n,op,res);
        return res;
}
// Func 2:
void findPowerSet(vector <int> ip, int i, int n, vector <int> op, vector <vector<int>> &res){
        res.push_back(op);
        if(i==n)
            return;
        for(int j=i;j<n;j++){
            op.push_back(ip[j]);
            findPowerSet(ip,j+1,n,op,res);
            op.pop_back();
        }
}
    

// Method 1: Using Recursion - By Picking and Not Picking
// Func 1:
vector <vector<int>> subsets(vector <int> &nums) {
        int n=nums.size();
        vector <vector<int>> res;
        vector <int> op;
        findPowerSet(nums,0,n,op,res);
        return res;
}
// Func 2:
void findPowerSet(vector <int> ip, int i, int n, vector <int> op, vector <vector<int>> &res){
        if(i==n){
            res.push_back(op);
            return;
        }
        op.push_back(ip[i]);
        findPowerSet(ip,i+1,n,op,res);
        op.pop_back();
        findPowerSet(ip,i+1,n,op,res);
}
    
    
