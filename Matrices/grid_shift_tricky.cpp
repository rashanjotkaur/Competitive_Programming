// https://leetcode.com/problems/shift-2d-grid/

// If k is 1 then new column is (j+1) and if k is k then new column is (j+k) and new column should in range [0,m-1]. So new column is (j+k)%m.
// For row, we have to first find the number of rows added to previous row which is equal to the number of times (j+k) exceeds m. So, number of rows added is (j+k)/m.
// So, new row is (i + (j+k)/m) and new row should in range [0,n-1]. So new column is (i + (j+k)/m)%n.

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        vector <vector<int>> res(r,vector <int> (c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int newCol = (j+k)%c;
                int newRol = (i+(j+k)/c)%r;
                res[newRol][newCol]=grid[i][j];
            }
        }
        return res;
    }
};



