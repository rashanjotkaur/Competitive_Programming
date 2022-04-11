// mat1 = r1 * c1
// mat2 = r2 * c2
// for matrix multiplication => c1=r2
// new matrix => r1 * c2

class Solution {
public:
    void Mutliply(vector<vector<int> >& mat1, vector<vector<int>>&mat2) {
        int r1=mat1.size();
        int c1=mat1[0].size();
        int r2=mat2.size();
        int c2=mat2[0].size();
       
        vector <vector<int>> res(r1,vector <int> (c2,0));
        if(c1==r2){
            int common=c1;
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    for(int k=0;k<common;k++)
                        res[i][j]+=mat1[i][k]*mat2[k][j];
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            cout<<"Multiplication is not possible"<<endl;
        }
    }
};
