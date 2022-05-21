// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

// Can be done using dp as we have to move in 4 directions -> left, right, up, down

// Method - BFS
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
int minimumCostPath(vector<vector<int>> &mat){
        int row=mat.size();
        if(row==0)
            return 0;
        int col=mat[0].size();
        
        vector <int> rows={0,0,-1,1};
        vector <int> cols={-1,1,0,0};
        
        vector <vector<int>> path(row,vector <int> (col,INT_MAX));
        priority_queue <ppi,vector <ppi>,greater<ppi>> pq;
        
        path[0][0]=mat[0][0];
        pq.push(make_pair(path[0][0],make_pair(0,0)));
        
    	  while(!pq.empty()){
              int w=pq.top().first;
              int rr=pq.top().second.first;
              int cc=pq.top().second.second;
              pq.pop();
              if(rr==row-1 && cc==col-1)
                  return w;
              for(int i=0;i<4;i++){
                  int r=rr+rows[i];
                  int c=cc+cols[i];
                  if(r<0 || r>=row) continue;
                  if(c<0 || c>=col) continue;

                  int dis=w+mat[r][c];
                  if(dis<path[r][c]){
                      path[r][c]=dis;
                      pq.push(make_pair(dis,make_pair(r,c)));
                  }
              }
        }
}
