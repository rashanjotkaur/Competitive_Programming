// Find all the subsets - duplicates are present in the array.
// https://leetcode.com/problems/subsets-ii/description/

// Method 2: Using the loop to skip the duplicates
// Func 1:
vector <vector<int>> subsetsWithDup(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector <vector<int>> res;
        vector <int> temp;
        allSubsets(nums,0,n,temp,res);
        return res;
}
// Func 2:
void allSubsets(vector <int> nums, int i, int n, vector <int> temp, vector<vector<int>> &res){
        res.push_back(temp);
        if(i==n)
            return;
        
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            allSubsets(nums,j+1,n,temp,res);
            temp.pop_back();
        }
}


// Method 1:
// Func 1:
vector <vector<int>> subsetsWithDup(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set <vector<int>> s;
        vector <int> temp;
        allSubsets(nums,0,n,temp,s);
        vector <vector<int>> res;
        for(auto x:s){
            vector <int> temp=x;
            res.push_back(temp);
        }
        return res;
}
// Func 2: 
void allSubsets(vector <int> nums, int i, int n, vector <int> temp, set<vector<int>> &s){
        if(i==n){
            s.insert(temp);
            return ;
        }
        temp.push_back(nums[i]);
        allSubsets(nums,i+1,n,temp,s);
        temp.pop_back();
        allSubsets(nums,i+1,n,temp,s);
}
    
