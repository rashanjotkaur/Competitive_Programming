// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Method 1 - Using priority queue
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
            if(pq.size()>k)
                pq.pop();  // k largest elements will be remaining at the priority queue
        }
        
        vector <int> ans(k);
        int i=0;
        while(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            ans[i]=idx;
            i++;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            int idx=ans[i];
            ans[i]=nums[idx];
        }
        return ans;
    }
};


// Method 2 - Without using priority queue
// In normal vector, we have to sort n elements --> nlogn
// whereas in priority queue, we sort k elements --> nlogk
class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        int n=nums.size();
        vector <pair<int,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back(make_pair(nums[i],i));
        sort(vec.begin(),vec.end());
        
        vector <int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(vec[n-1-i].second);
    
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            int idx=ans[i];
            ans[i]=nums[idx];
        }
        return ans;
    }
};
