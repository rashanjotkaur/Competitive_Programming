// https://leetcode.com/problems/unique-paths/

// Method 1 - Using DP
class Solution {
public:
    int uniquePaths(int row, int col) {
        vector <vector<int>> dp(row,vector <int> (col,0));
        for(int r=0;r<row;r++)
            dp[r][0]=1;
        for(int c=1;c<col;c++)
            dp[0][c]=1;
        for(int r=1;r<row;r++){
            for(int c=1;c<col;c++){
                dp[r][c]=dp[r][c]+dp[r-1][c]+dp[r][c-1];
            }
        }
        return dp[row-1][col-1];
    }
};


// Method 2 - Causes TLE 
class Solution {
public:
    void dfs(vector <vector<int>> &grid, int r, int c, int row, int col, int &paths){
        if(r<0 || r>=row || c<0 || c>=col)
            return ;
        if(r==row-1 && c==col-1){
            paths++;
            return ;
        }
        dfs(grid,r,c+1,row,col,paths);
        dfs(grid,r+1,c,row,col,paths);
    }
    int uniquePaths(int row, int col) {
        vector <vector<int>> grid(row,vector <int> (col,1));
        int paths=0;
        dfs(grid,0,0,row,col,paths);
        return paths;
    }
};


