// Combination Sum I
// Problem Link: https://leetcode.com/problems/combination-sum/description/
// Problem Link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
// https://www.geeksforgeeks.org/combinational-sum/

// We can use each element any number of times. 

// Method 3: Best Approach 
// 1. Since, we can use each element any number of times. 
// 2. So, if duplicates are there in the array, then we are checking for the same combination of sequences again and again.
// 3. Duplicate Sequences are getting created.
// 4. Hence, first remove the duplicates from the array.
// 5. For removing duplicates - Sort the array first and then use sliding window for comparing.
void combinations(vector <int> nums, int i, int n, int target, vector <int> temp, set<vector<int>> &s){
        if(target<0)
            return;
        if(i==n){
            if(target==0)
                s.insert(temp);
            return ;
        }
        temp.push_back(nums[i]);
        combinations(nums,i,n,target-nums[i],temp,s);
        temp.pop_back();
        combinations(nums,i+1,n,target,temp,s);
}
vector <vector<int> > combinationSum(vector <int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cmp=nums[0];
        int idx=1;
        for(int i=1;i<n;i++){
            if(cmp!=nums[i]){
                nums[idx]=nums[i];
                cmp=nums[idx];
                idx++;
            }
        }
        vector <vector<int>> res;
        set <vector<int>> s;
        vector <int> temp;
        combinations(nums,0,idx,target,temp,s);
        for(auto x:s){
            temp=x;
            res.push_back(temp);
        }
        return res;
}


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

