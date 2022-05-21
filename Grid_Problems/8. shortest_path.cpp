// https://leetcode.com/problems/minimum-path-sum/

// Method 1
class Solution {
public:
    int minPathSum(vector <vector<int>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        vector <vector<int>> dp(row,vector <int> (col,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<row;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        
        for(int j=1;j<col;j++)
            dp[0][j]=dp[0][j-1]+grid[0][j];
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++)
                dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[row-1][col-1];
    }
};

// Method 2
class Solution {
public:
    int minPathSum(vector <vector<int>> &path) {
        int n=path.size();
        int m=path[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && j>0)
                    path[i][j]=path[i][j]+min(path[i-1][j],path[i][j-1]);
                else if(i>0)
                    path[i][j]=path[i][j]+path[i-1][j];
                else if(j>0)
                    path[i][j]=path[i][j]+path[i][j-1];
            }
        }
        return path[n-1][m-1];
    }
};
