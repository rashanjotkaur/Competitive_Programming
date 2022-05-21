// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
// https://www.geeksforgeeks.org/maximum-path-sum-matrix/

#include <bits/stdc++.h>
using namespace std;

int maxPath(vector <vector<int>> mat, int row, int col){
    int dp[row+1][col+1];
    for(int i=0;i<=row;i++)
        dp[i][0]=0;
    for(int j=0;j<=col;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++)
            dp[i][j]=max({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]})+mat[i-1][j-1];
    }  
    // for(int i=1;i<=row;i++){
    //     for(int j=1;j<=col;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // } 
    int res=INT_MIN;
    for(int j=0;j<col;j++)
      res=max(res,dp[row][j]);
    return res;
}

int main(){
    int row,col;
    cin>>row>>col;
    vector <vector<int>> mat(row, vector<int>(col)); 
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++)
        cin>>mat[i][j];
    }	
    cout<<maxPath(mat,row,col)<<endl;
    return 0;
}
