// Combination Sum
// Problem Link: https://leetcode.com/problems/combination-sum/description/
// Problem Link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
// https://www.geeksforgeeks.org/combinational-sum/


// Method 2: Same as Previous - Just Subtracting from the target
void combinations(vector <int> nums, int i, int n, int target, vector <int> temp, vector<vector<int>> &res){
        if(target<0)  
            return;
        if(i==n){
            if(target==0)
                res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        combinations(nums,i,n,target-nums[i],temp,res);
        temp.pop_back();
        combinations(nums,i+1,n,target,temp,res);
}
vector <vector<int>> combinationSum(vector <int> &nums, int target) {
        int n=nums.size();
        vector <vector<int>> res;
        vector <int> temp;
        combinations(nums,0,n,target,temp,res);
        return res;
}

// OR

void combinations(vector <int> nums, int i, int n, int target, vector <int> temp, vector<vector<int>> &res){
        if(i==n){
            if(target==0)
                res.push_back(temp);
            return;
        }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            combinations(nums,i,n,target-nums[i],temp,res);
            temp.pop_back();
        }
        combinations(nums,i+1,n,target,temp,res);
}
vector <vector<int>> combinationSum(vector <int> &nums, int target) {
        int n=nums.size();
        vector <vector<int>> res;
        vector <int> temp;
        combinations(nums,0,n,target,temp,res);
        return res;
}



// Method 1: Using Recursion - Trying all possible sequences, as we did in "Print all subsequence questions".
// Works on Leetcode, but gives TLE in GFG 
void combinations(vector <int> nums, int i, int n, int currSum, int target, vector <int> temp, set<vector<int>> &s){
        if(currSum>target)  
            return;
        if(i==n){
            if(currSum==target){
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
            return;
        }
        currSum=currSum+nums[i];
        temp.push_back(nums[i]);
        combinations(nums,i,n,currSum,target,temp,s);
        currSum=currSum-nums[i];
        temp.pop_back();
        combinations(nums,i+1,n,currSum,target,temp,s);
}
vector <vector<int> > combinationSum(vector <int> &nums, int target) {
        int n=nums.size();
        set <vector<int>> s;
        vector <vector<int>> res;
        vector <int> temp;
        combinations(nums,0,n,0,target,temp,s);
        for(auto x:s){
            temp=x;
            res.push_back(temp);
        }
        return res;
}

