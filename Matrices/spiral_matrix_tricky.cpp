// https://leetcode.com/problems/spiral-matrix/
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

class Solution {
public:
    vector <int> spiralOrder(vector <vector<int>> &mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int top=0;
        int left=0;
        int right=cols-1;
        int bottom=rows-1;
        
        vector <int> res;
        while(top<=bottom && left<=right){ 
            for(int j=left;j<=right;j++) 
                res.push_back(mat[top][j]); 
            top++; 
            
            for(int i=top;i<=bottom;i++)
                res.push_back(mat[i][right]); 
            right--; 
            
            if(top<=bottom) { 
                for(int j=right;j>=left;j--) 
                    res.push_back(mat[bottom][j]); 
                bottom--; 
            } 
            if(left<=right){ 
                for(int i=bottom;i>=top;i--)
                    res.push_back(mat[i][left]); 
                left++; 
            } 
        } 
        
        return res;
    }
};
