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



