//  https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/#

// Method - DFS 
// Function - Main
bool is_Possible(vector <vector<int>> &grid){
        int row=grid.size();
        if(row==0)
            return false;
        int col=grid[0].size();
        int sr,sc,dr,dc;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    dr=i;
                    dc=j;
                }
            }
        }
        return dfs(grid,sr,sc,dr,dc,row,col);
}
// Funtion - 1
bool dfs(vector <vector<int>> &grid, int r, int c, int dr, int dc, int row, int col){
        if(r<0 || r>=row || c<0 || c>=col)
            return false;
        if(grid[r][c]==0)
            return false;
        if(r==dr && c==dc)
            return true;
        
        grid[r][c]=0;
        bool up=dfs(grid,r-1,c,dr,dc,row,col);
        bool down=dfs(grid,r+1,c,dr,dc,row,col);
        bool left=dfs(grid,r,c-1,dr,dc,row,col);
        bool right=dfs(grid,r,c+1,dr,dc,row,col);
        if(up || down || left || right)
            return true;
}
    



// Method - BFS
// Method 1
typedef pair<int,int> pi;
// Function - Main
bool is_Possible(vector <vector<int>> &grid){
        int row=grid.size();
        if(row==0)
            return false;
        int col=grid[0].size();
        int sr,sc,dr,dc;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    dr=i;
                    dc=j;
                }
            }
        }
        return bfs(grid,sr,sc,dr,dc,row,col);
}
// Function - 1
bool bfs(vector <vector<int>> &grid, int sr, int sc, int dr, int dc, 
             int row, int col){
        queue <pi> q;
        vector <int> rows{-1,1,0,0};
        vector <int> cols{0,0,-1,1};
        
        q.push({sr,sc});
        grid[sr][sc]=0;
        
        while(!q.empty()){
            int rr=q.front().first;
            int cc=q.front().second;
            if(rr==dr && cc==dc)
                return true;
            q.pop();
            for(int i=0;i<4;i++){
                int r=rr+rows[i];
                int c=cc+cols[i];
                if(r<0 || r>=row) continue;
                if(c<0 || c>=col) continue;
                if(grid[r][c]){
                    q.push({r,c});
                    grid[r][c]=0;
                }
            }
        }
        return false;
}
   

// Method 2 
typedef pair<int,int> pi;
// Function - Main
bool is_Possible(vector <vector<int>> &grid){
        int row=grid.size();
        if(row==0)
            return false;
        int col=grid[0].size();
        int sr,sc,dr,dc;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    dr=i;
                    dc=j;
                }
            }
        }
        return bfs(grid,sr,sc,dr,dc,row,col);
}
// Function - 1
bool bfs(vector <vector<int>> &grid, int sr, int sc, int dr, int dc, int row, int col){
        vector <vector<bool>> vis(row,vector <bool> (col,false));
        queue <pi> q;
        vector <int> rows{-1,1,0,0};
        vector <int> cols{0,0,-1,1};
        
        q.push({sr,sc});
        vis[sr][sc]=true;
        
        while(!q.empty()){
            int rr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=rr+rows[i];
                int c=cc+cols[i];
                if(r<0 || r>=row) continue;
                if(c<0 || c>=col) continue;
                if(!vis[r][c] && grid[r][c]){
                    vis[r][c]=true;
                    q.push({r,c});
                }
            }
        }
        return vis[dr][dc];
}

    
// Method 3
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
bool bfs(vector <vector<int>> mat,int n,int sr,int sc,int dr,int dc){
      vector <vector <bool>> vis(n,vector <bool> (n,false)); 
    	queue <pi> q;
    	
    	vector <int> row{-1,1,0,0};
      vector <int> col{0,0,-1,1};
    	
    	q.push(make_pair(sr,sc));
    	while(!q.empty()){
    	    int rr=q.front().first;
    	    int cc=q.front().second;
    	    q.pop();
    	    if(vis[rr][cc]) continue;
    	    vis[rr][cc]=true;
    	    for(int i=0;i<4;i++){
    	        int r=rr+row[i];
    	        int c=cc+col[i];
    	        if(r<0 || r>=n) continue;
    	        if(c<0 || c>=n)  continue;
    	        if(mat[r][c] && !vis[r][c]){
    	            q.push(make_pair(r,c));
    	        }
    	    }
    	}
    	return vis[dr][dc];
}
int main() {
	int n;
    	cin>>n;
    	vector <vector<int>> mat(n,vector <int> (n));
    	int sr,sc,dr,dc;
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<n;j++){
    	        cin>>mat[i][j];
    	        if(mat[i][j]==1){
    	            sr=i;
    	            sc=j;
    	        }
    	        if(mat[i][j]==2){
    	            dr=i;
    	            dc=j;
    	        }
    	    }
      }
      // n=rows & columns
      cout<<bfs(mat,n,sr,sc,dr,dc)<<endl;
      return 0;
}
