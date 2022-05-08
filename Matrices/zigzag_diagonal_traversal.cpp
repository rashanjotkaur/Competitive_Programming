// https://leetcode.com/problems/diagonal-traverse/
// https://www.geeksforgeeks.org/print-matrix-in-zig-zag-fashion/

class Solution {
public:
    vector<int> findDiagonalOrder(vector <vector<int>> &mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector <int> res;
        int r=0;
        bool useStack=false;
        while(r<rows){
            int r1=r;
            int c1=0;
            stack <int> s;
            if(useStack){
                while(r1>=0 && c1<cols){
                    s.push(mat[r1][c1]);
                    r1--;
                    c1++;
                }
                while(!s.empty()){
                    int x=s.top();
                    res.push_back(x);
                    s.pop();
                }
            }
            else{
                while(r1>=0 && c1<cols){
                    res.push_back(mat[r1][c1]);
                    r1--;
                    c1++;
                }
            }
            r++;
            useStack=!useStack;
        }
        
        
        int c=1;
        while(c<cols){
            int r1=rows-1;
            int c1=c;
            stack <int> s;
            if(useStack){
                while(r1>=0 && c1<cols){
                    s.push(mat[r1][c1]);
                    r1--;
                    c1++;
                }
                while(!s.empty()){
                    int x=s.top();
                    res.push_back(x);
                    s.pop();
                }
            }
            else{
                while(r1>=0 && c1<cols){
                    res.push_back(mat[r1][c1]);
                    r1--;
                    c1++;
                }
            }
            c++;  
            useStack=!useStack;
        }
        return res;
    }
};
