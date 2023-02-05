// Problem Link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
vector <int> mergeKArrays(vector <vector<int>> mat){
        int r=mat.size();
        int c=mat[0].size();
        int n=r*c;
        vector <int> res(n);
        priority_queue <ppi,vector<ppi>,greater<ppi>> pq;
        for(int i=0;i<r;i++)
            pq.push({mat[i][0],{i,0}});
        int m=0;
        while(!pq.empty()){
            res[m]=pq.top().first;
            m++;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(j<c-1)
                pq.push({mat[i][j+1],{i,j+1}});
        }
        return res;
}
