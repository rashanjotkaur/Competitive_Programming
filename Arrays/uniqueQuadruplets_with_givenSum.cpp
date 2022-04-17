// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
// https://leetcode.com/problems/4sum/

// Method 1: Using Two Pointer loop | O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set <vector<int>> set;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1;
                int r=n-1;
                int sum=k-(nums[i]+nums[j]);
                while(l<r){
                    if(sum==nums[l]+nums[r]){
                        // cout<<sum<<endl;
                        vector <int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[l];
                        temp[3]=nums[r];
                        set.insert(temp);
                        l++;
                        r--;
                    }
                    else if(sum>nums[l]+nums[r])
                        l++;
                    else
                        r--;
                }
            }
        }
        vector <vector<int>> res;
        for(auto it=set.begin();it!=set.end();it++){
            vector <int> temp=*it;
            res.push_back(temp);
        }
        return res;
    }
};



// Method 2: Using unordered_map and lot of brain...
https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4) return ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]+nums[j]].push_back({i,j});
            }
        }
        for(int i=0;i<n-1;i++){
            if(i>0 and nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1])  
                    continue;
                int sum=target-nums[i]-nums[j];
                if(mp.find(sum)!=mp.end()){
                    for(auto it : mp[sum]){
                        int k=it.first;
                        int l=it.second;
                        if(j<k && k<l){
                            if(!ans.empty()&& ans.back()[0]==nums[i]&&ans.back()[1]==nums[j]&&ans.back()[2]==nums[k]&&ans.back()[3]==nums[l]) continue;
                            vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};



