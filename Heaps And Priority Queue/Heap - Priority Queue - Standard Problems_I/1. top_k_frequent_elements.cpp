// Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

// Method 1: Using HashMap & Priority Queue
typedef pair<int,int> pi;
vector <int> topKFrequent(vector <int> &nums, int k) {
        int n=nums.size();
        unordered_map <int,int> ump;
        for(int i=0;i<n;i++)
            ump[nums[i]]++;
        priority_queue <pi,vector<pi>,greater<pi>> pq;
        for(auto x:ump){
            pq.push({x.second,x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector <int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
}


// Method 2: 
typedef pair<int,int> pi;
struct cmp {
      bool operator() (const pi a,const pi b) {
          if(a.first == b.first)
            return a.second < b.second;
         return a.first>b.first;
      }  
};
vector<int> topKFrequent(vector<int>& num, int k) {
        unordered_map <int,int> ump;
        for(int i=0;i<num.size();i++)
                ump[num[i]]++;
        priority_queue <pi,vector<pi>,cmp> pq;
        for(auto it=ump.begin();it!=ump.end();it++){
            int val=it->first;
            int fre=it->second;
            pq.push(make_pair(fre,val));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector <int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end()); // Return Sorted Vector
        return res;
}
