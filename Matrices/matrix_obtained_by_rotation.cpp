// Determine Whether Matrix Can Be Obtained By Rotation
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

// Logice is same in both codes, only way of writing is different

// Way 1 of Writing 
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int r=mat.size();
        int c=mat[0].size();
        
        // 1st rotation 90 degree - clockwise
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<r;i++)
            reverse(mat[i].begin(),mat[i].end());
        if(mat==target)
            return true;
        
            
        // 2nd rotation 90 degree - clockwise
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<r;i++)
            reverse(mat[i].begin(),mat[i].end());
        if(mat==target)
            return true;
        
        
        // 3rd rotation 90 degree - clockwise
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<r;i++)
            reverse(mat[i].begin(),mat[i].end());
        if(mat==target)
            return true;
    
        
        // 4th rotation 90 degree - clockwise
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<r;i++)
            reverse(mat[i].begin(),mat[i].end());
        if(mat==target)
            return true;
        
        return false;
    }
};

// Way 2 of writing - in Compact form 
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int r=mat.size();
        int c=mat[0].size();
        
        if(mat==target)
            return true;
        
        int degree=3;
        
        while(degree){
            for(int i=0;i<r;i++){
                for(int j=i+1;j<c;j++)
                    swap(mat[i][j],mat[j][i]);
            }
            for(int i=0;i<r;i++)
                reverse(mat[i].begin(),mat[i].end());
            if(mat==target)
                return true;
            degree--;
        }
        
        return false;
    }
};

