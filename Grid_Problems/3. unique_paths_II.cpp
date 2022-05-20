// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &grid) {
        // obstacleGrid - here we have obstacles in the grid
        if(grid[0][0]==1)
            return 0;
        
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        
        vector <vector<int>> dp(row,vector <int> (col,0));
        dp[0][0]=1;
        for(int r=1;r<row;r++){
            if(grid[r][0]==1)
                break;
            dp[r][0]=1;
        }
        for(int c=1;c<col;c++){
            if(grid[0][c]==1)
                break;
            dp[0][c]=1;
        }
        for(int r=1;r<row;r++){
            for(int c=1;c<col;c++){
                if(grid[r][c]==1)
                    dp[r][c]=-1;
            }
        }
        for(int r=1;r<row;r++){
            for(int c=1;c<col;c++){
                if(dp[r][c]!=-1){
                    if(dp[r-1][c]!=-1)
                        dp[r][c]=dp[r][c]+dp[r-1][c];
                    if(dp[r][c-1]!=-1)
                        dp[r][c]=dp[r][c]+dp[r][c-1];
                }
            }
        }
        if(dp[row-1][col-1]==-1)
            return 0;
        return dp[row-1][col-1];
    }
};
