// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector <vector<int>> &mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        bool row_flag=false;
        bool col_flag=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && mat[i][j]==0)
                    row_flag=true;
                if(j==0 && mat[i][j]==0)
                    col_flag=true;
                if(mat[i][j]==0){
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j]=0;
            }
        }
        if(row_flag){ //put zeroes in 0th row
            for(int j=0;j<cols;j++)
                mat[0][j]=0;
        }
        if(col_flag){ //put zeroes in 0th column
            for(int i=0;i<rows;i++)
                mat[i][0]=0;
        }
    }
};
