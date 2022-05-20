// https://leetcode.com/problems/max-area-of-island/

// Function - Main
int maxAreaOfIsland(vector <vector<int>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        int maxArea=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    int area=0;
                    dfs(grid,r,c,row,col,area);
                    maxArea=max(maxArea,area);   
                }
            }
        }
        return maxArea;
}

// Function - 1
void dfs(vector <vector<int>> &grid, int r, int c, int row, int col, int &area){
        if(r<0 || r>=row || c<0 || c>=col)
            return ;
        if(grid[r][c]==0)
            return;
        area++;
        grid[r][c]=0;
        dfs(grid,r-1,c,row,col,area);
        dfs(grid,r+1,c,row,col,area);
        dfs(grid,r,c-1,row,col,area);
        dfs(grid,r,c+1,row,col,area);
}
