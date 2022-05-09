// Difficult - DP
// Link for video: https://www.youtube.com/watch?v=ppWCu4Z9h08&ab_channel=Pepcoding
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

// Solution
class Solution {
public:
    int min(int a,int b,int c){
        if(a<=b && a<=c)
            return a;
        if(b<=a && b<=c)
            return b;
        return c;
    }
    int countSquares(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int count=0;
        int dp[rows][cols];
        for(int i=0;i<rows;i++){
            dp[i][0]=mat[i][0];
            count+=dp[i][0];
        }
        for(int j=1;j<cols;j++){
            dp[0][j]=mat[0][j];
            count+=dp[0][j];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
                dp[i][j]++;
                count+=dp[i][j];
            }
        }
        return count;
    }
};
