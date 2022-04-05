// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int oriEle=mat.size()*mat[0].size();
        int newEle=r*c;
        // cout<<oriEle<<" "<<newEle<<endl;
        if(newEle!=oriEle)
            return mat;
        vector <vector<int>> res(r,vector <int> (c,0));
        int row=0,col=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                res[row][col]=mat[i][j];
                col++;
                if(col==c){
                    row++;
                    col=0;
                }
            }
        }
        return res;
    }
};
