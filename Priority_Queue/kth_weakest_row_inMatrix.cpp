// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
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
};
