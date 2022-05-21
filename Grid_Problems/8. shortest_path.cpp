// https://leetcode.com/problems/minimum-path-sum/
// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0/?track=md-graph&batchId=144

// DFS
// Method 1 - Space Complexity less than Method 2
// Don't use extra dp as We used in Method 2
class Solution {
public:
    int minPathSum(vector <vector<int>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        for(int i=1;i<row;i++)
            grid[i][0]+=grid[i-1][0];
        
        for(int j=1;j<col;j++)
            grid[0][j]+=grid[0][j-1];
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++)
                grid[i][j]=min(grid[i][j-1],grid[i-1][j])+grid[i][j];
        }
        return grid[row-1][col-1];
    }
};

// Method 2
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

// Method 3 - Most optimal
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


// Using BFS - Not Fast
class Solution {
public:
    typedef pair<int,int> pi;
    typedef pair<int,pi> ppi;
    int minPathSum(vector <vector<int>> &grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        
        // Only two options as we can move:
        // Right
        // Down
        vector <int> rows={1,0};   // for moving down
        vector <int> cols={0,1};   // for moving right
        
        priority_queue <ppi,vector<ppi>,greater<ppi>> pq;  //min at top
        vector <vector<int>> path(row,vector <int> (col,INT_MAX));
        
        path[0][0]=0;
        pq.push({grid[0][0],{0,0}});
        
        while(!pq.empty()){
            int w=pq.top().first;
            int rr=pq.top().second.first;
            int cc=pq.top().second.second;
            pq.pop();
            if(rr==row-1 && cc==col-1)
                return w;
            for(int i=0;i<2;i++){
                int r=rr+rows[i];
                int c=cc+cols[i];
                if(r<0 || r>=row)
                    continue;
                if(c<0 || c>=col)
                    continue;
                int dis=w+grid[r][c];
                if(dis<path[r][c]){
                    path[r][c]=dis;
                    pq.push({dis,{r,c}});
                }
            }
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++)
        //         cout<<path[i][j]<<" ";
        //     cout<<endl;
        // }
        return -1;
    }
};
