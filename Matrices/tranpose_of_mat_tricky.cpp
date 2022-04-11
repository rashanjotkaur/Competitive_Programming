// https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        if(r==c){ 
            //Square Matrix
            for(int i=0;i<r;i++){
                for(int j=i+1;j<c;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            return mat;
        }
        else{
            // Rectangular Matrix
            vector <vector<int>> res(c,vector <int> (r));
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    res[j][i]=mat[i][j];
                }
            }
            return res;   
        }
    }
};
