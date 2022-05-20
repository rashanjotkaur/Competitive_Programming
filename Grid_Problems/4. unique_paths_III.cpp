// https://leetcode.com/problems/unique-paths-iii/

// Function - Main
int uniquePathsIII(vector <vector<int>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        int paths=row*col;
        
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
                else if(grid[i][j]==-1)
                    paths--;
            }
        }
        
        int count=1,ans=0;
        dfs(grid,sr,sc,dr,dc,row,col,count,paths,ans);
        return ans;
}

// Method - 1
void dfs(vector <vector<int>> grid, int r, int c, int dr, int dc, int row, int col, int count, int paths, int &ans){
        if(r<0 || r>=row || c<0 || c>=col)
            return ;
        if(grid[r][c]==-1)
            return ;
        if(r==dr && c==dc && count==paths){
            ans++;
            return ;
        }
        grid[r][c]=-1;
        dfs(grid,r+1,c,dr,dc,row,col,count+1,paths,ans);
        dfs(grid,r-1,c,dr,dc,row,col,count+1,paths,ans);
        dfs(grid,r,c+1,dr,dc,row,col,count+1,paths,ans);
        dfs(grid,r,c-1,dr,dc,row,col,count+1,paths,ans);
}
