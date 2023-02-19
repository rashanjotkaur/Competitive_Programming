// Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/description/


// Method 2: Best Approach
// 1. First Sort the array as we need to skip the same elements - so that recursion shouldn't be used in these cases.
// 2. Go through Notes: Or Watch Striver.
//    https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9
//    Striver Solution: https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
// Func 1:
vector <vector<int>> combinationSum2(vector <int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector <vector<int>> res;
        vector <int> temp;
        uniqueCombinations(nums,0,n,target,temp,res);
        return res;
}
// Func 2:
void uniqueCombinations(vector <int> nums, int i, int n,int target, vector <int> temp, vector<vector<int>> &res){
        if(target==0){
            res.push_back(temp);
            return ;
        }
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])   
                continue;
            if(nums[i]>target)  
                break;
            temp.push_back(nums[j]);
            uniqueCombinations(nums,j+1,n,target-nums[j],temp,res);
            temp.pop_back();
        }
}


// Method 1: Trying all possible sequences.
// Func 1: 
vector <vector<int>> combinationSum2(vector <int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector <vector<int>> res;
        set <vector<int>> s;
        vector <int> temp;
        uniqueCombinations(nums,0,n,target,temp,s);
        for(auto x:s){
            temp=x;
            res.push_back(temp);
        }
        return res;
}
// Func 2:
void uniqueCombinations(vector <int> nums, int i, int n,int target, vector <int> temp, set<vector<int>> &s){
            if(target<0)
                return;
            if(i==n){
                if(target==0)
                    s.insert(temp);
                return ;
            }
            temp.push_back(nums[i]);
            uniqueCombinations(nums,i+1,n,target-nums[i],temp,s);
            temp.pop_back();
            uniqueCombinations(nums,i+1,n,target,temp,s);
}
   
    
