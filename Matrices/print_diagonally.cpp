// https://practice.geeksforgeeks.org/problems/print-diagonally4331/1#

// Explaination : https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> mat){
		int rows=mat.size();
        int cols=mat[0].size();
        vector <int> res;
        
        int c=0;
        while(c<cols){
            int r1=0;
            int c1=c;
            while(r1<rows && c1>=0){
                res.push_back(mat[r1][c1]);
                r1++;
                c1--;
            }
            c++;
        }
        
        int r=1;
        while(r<rows){
            int r1=r;
            int c1=cols-1;
            while(r1<rows && c1>=0){
                res.push_back(mat[r1][c1]);
                r1++;
                c1--;
            }
            r++;  
        }
        return res;
	}

};
