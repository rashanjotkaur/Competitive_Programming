// https://leetcode.com/problems/number-of-islands/

// Function - Main
int numIslands(vector <vector<char>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        int islands=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                // Here, we are checking for the connected components
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j,row,col);
                }
        }
        return islands;
}

// Function - 1
void dfs(vector <vector<char>> &grid, int i, int j, int row, int col){
        if(i<0 || i>=row || j<0 || j>=col)
            return ;
        if(grid[i][j]=='0')
            return ;
        grid[i][j]='0';
        dfs(grid,i-1,j,row,col);
        dfs(grid,i+1,j,row,col);
        dfs(grid,i,j-1,row,col);
        dfs(grid,i,j+1,row,col);
}
