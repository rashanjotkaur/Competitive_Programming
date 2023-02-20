// Print sums of all subsets of a given set
// Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Func 1:
vector <int> subsetSums(vector <int> nums, int n){
        vector <int> res;
        findAllSubsets(nums,0,n,0,res);
        return res;
}
// Func 2:
void findAllSubsets(vector <int> nums, int i, int n, int sum, vector <int> &res){
        if(i==n){
            res.push_back(sum);
            return;
        }
        findAllSubsets(nums,i+1,n,sum+nums[i],res);
        findAllSubsets(nums,i+1,n,sum,res);
}
    
