// 3 Sum
// https://leetcode.com/problems/3sum/description/

// Method 2: Without using set: Extra Space - Preferred
vector <vector<int>> threeSum(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector <vector<int>> res;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int x=nums[i]+nums[j]+nums[k];
                if(x==0){
                    vector <int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    res.push_back(temp);
                    int jtemp=j,ktemp=k;
                    while(j<k && nums[j]==nums[jtemp]) j++;
                    while(j<k && nums[k]==nums[ktemp]) k--;
                }
                else if(x<0)
                    j++;
                else
                    k--;
            }
            while(i<n-1 && nums[i]==nums[i+1])
                i++;
        }
        return res;
}


// Method 1: Using set. 
// 1. As we have to remove the duplicate combinations, we will store in set first.
// 2. Then, we will move to combinations from set to vector.
vector <vector<int>> threeSum(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set <vector<int>> s;
        vector <vector<int>> res;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int x=nums[i]+nums[j]+nums[k];
                if(x==0){
                    vector <int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    s.insert(temp);
                    j++;
                    k--;
                }
                else if(x<0)
                    j++;
                else
                    k--;
            }
        }
        for(auto x:s)
            res.push_back(x);
        return res;
}

