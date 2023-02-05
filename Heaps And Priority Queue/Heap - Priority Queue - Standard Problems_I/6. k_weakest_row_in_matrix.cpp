// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Method 1: Using Max Priority Queue 
// Space Complexity: O(k)
vector<int> kWeakestRows(vector <vector<int>> &mat, int k) {
        int rows=mat.size();
        int cols=mat[0].size();
        priority_queue <pair<int,int>> pq;
        for(int i=0;i<rows;i++){
            int count=0;
            for(int j=0;j<cols;j++)
                count+=mat[i][j];
            pq.push({count,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector <int> ans(k);
        int i=k-1;
        while(!pq.empty()){
            ans[i]=pq.top().second;
            pq.pop();
            i--;
        }
        return ans;
}

// Method 2: Using Min Priority Queue 
// Space Complexity: O(n)
typedef pair<int,int> pi;
vector <int> kWeakestRows(vector <vector<int>> &mat, int k) {
        int r=mat.size();
        int c=mat[0].size();
        priority_queue <pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<r;i++){
            int sum=0;
            int j=0;
            while(j<c && mat[i][j]){
                sum++;
                j++;
            }
            pq.push({sum,i});
        }
        vector <int> res;
        while(k && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
}
