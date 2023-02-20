// Find all possible Subsets 
// Find the Power Set
// Problem Link: https://leetcode.com/problems/subsets/

// Func 1:
vector<vector<int>> subsets(vector <int> &nums) {
        int n=nums.size();
        vector <vector<int>> res;
        if(n==0)
            return res;
        vector <int> op;
        findPowerSet(nums,0,op,res);
        return res;
}
// Func 2:
void findPowerSet(vector <int> ip, int i, vector <int> op, vector <vector<int>> &res){
        if(i==ip.size()){
            res.push_back(op);
            return;
        }
        // Case 1: Picking the element at index i
        op.push_back(ip[i]);
        findPowerSet(ip,i+1,op,res);
        op.pop_back();
        // Case 2: Not Picking the element at index i
        findPowerSet(ip,i+1,op,res);     
}
    
