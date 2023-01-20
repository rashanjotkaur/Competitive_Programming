// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
// https://leetcode.com/problems/4sum/

// Method 1: Sort -> Use 3 ptr + Binary Search
// Time Complexity: O(n3*logn+nlogn)=O(n3*logn)
// Space Complexity: O(n)
// Func 1: Gives TLE for n>=100
vector <vector<int>> fourSum(vector <int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set <vector<int>> s;
        for(int i=0;i<n-3;i++){
            long long newTarget1=target-nums[i];
            for(int j=i+1;j<n-2;j++){
                long long newTarget2=newTarget1-nums[j];
                for(int k=j+1;k<n-1;k++){
                    long long newTarget3=newTarget2-nums[k];
                    int idx=binarySearch(nums,k+1,n-1,newTarget3);
                    if(idx!=-1){
                        vector <int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[idx]);
                        s.insert(temp);
                    }
                }
            }
        }
        vector <vector<int>> res;
        for(auto x:s)
            res.push_back(x);
        return res;
}
//  Func 2:
int binarySearch(vector <int> nums, int l, int r, int key){
        if(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==key)
                return mid;
            if(nums[mid]<key)
                return binarySearch(nums,mid+1,r,key);
            return binarySearch(nums,l,mid-1,key);
        }
        return -1;
}
   

// Method 2: Using Two Pointer loop | O(n^3)
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


// Method 3: Using unordered_map and lot of brain... - Gives TLE in some cases(Hash Map Solution)
// Solution: https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/
// Approach:
// 1. Store sums of all pairs in a hash table.
// 2. Traverse through all pairs again and search for X – (current pair sum) in the hash table.
// 3. If a pair is found with the required sum, then make sure that all elements are distinct array elements and an element is not considered more than once.

// Way 1: Using unordered_map <int,pair<int,int>> ump --> this will store only one pair for particular SUM.
// Some Cases from LeetCode gets failed using this
vector <vector<int>> fourSum(vector <int> &nums, int target) {
        vector <vector<int>> res;
        int n=nums.size();
        if(n<4) 
            return res;
        unordered_map<long long,pair<long long,long long>> ump;
        set <vector<int>> s;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long sum=nums[i]+nums[j];
                ump[sum]={i,j};
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long sum=target-(long long)(nums[i]+nums[j]);
                if(ump.find(sum)!=ump.end()){
                    int p=ump[sum].first;
                    int q=ump[sum].second;
                    if(p!=i && p!=j && q!=i && q!=j){
                        vector <int> temp={nums[i],nums[j],nums[p],nums[q]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        for(auto x:s)
            res.push_back(x);
        return res;
}

// Way 2: Using unordered_map <int,vector<pair<int,int>>> ump --> this will store all the pairs in vector for particular SUM.
// Gives TLE on Leetcode, but worked on GFG.
vector<vector<int> > fourSum(vector<int> &nums, int X) {
        int n=nums.size();
        // Instead of using unordered_map<int, pair<int,int>> ump, use vector<pair<int,int>> as multiple pairs can create the same sum.
        unordered_map<int, vector<pair<int,int>>> ump;
        set <vector<int>> s;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int sum=nums[i]+nums[j];
                if(ump.find(X-sum)!=ump.end()){
                    vector <pair<int,int>> vec=ump[X-sum];
                    // cout<<"vector: "<<vec.size()<<endl;
                    for(int k=0;k<vec.size();k++){
                        pair <int,int> p=vec[k];
                        // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[p.first]<<" "<<nums[p.second]<<endl;
                        if (p.first != i && p.first != j && p.second != i && p.second != j) {
                            vector <int> temp(4);
                            temp[0]=nums[i];
                            temp[1]=nums[j];
                            temp[2]=nums[p.first];
                            temp[3]=nums[p.second];
                            sort(temp.begin(),temp.end());
                            s.insert(temp);
                        }
                    }
                }
                ump[nums[i]+nums[j]].push_back({i,j});
            }
        }
        vector <vector<int>> res;
        for(auto x:s)
            res.push_back(x);
        return res;
}

// Way 3: Best and Preferred Approach - Worked on Leet Code Also.
vector <vector<int>> fourSum(vector <int> &nums, int target) {
        vector <vector<int>> ans;
        int n=nums.size();
        if(n<4) 
            return ans;
        sort(nums.begin(),nums.end());
        unordered_map<long long,vector<pair<long long,long long>>> ump;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long sum=nums[i]+nums[j];
                ump[sum].push_back({i,j});
            }
        }
        for(int i=0;i<n-1;i++){
            if(i>0 and nums[i]==nums[i-1]) //as we don't want to repeat the pairs
                continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1])  //as we don't want to repeat the pairs
                    continue;
                long long sum=target-(long long)(nums[i]+nums[j]);
                if(ump.find(sum)!=ump.end()){
                    for(auto x : ump[sum]){
                        int p=x.first;
                        int q=x.second;
                        if(j<p && p<q){
                            if(!ans.empty() && ans.back()[0]==nums[i] && ans.back()[1]==nums[j] && 
                                ans.back()[2]==nums[p] && ans.back()[3]==nums[q]) 
                                    continue;
                            vector <int> temp={nums[i],nums[j],nums[p],nums[q]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
}




