// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector <vector<int>> res(r);
        if(r==1 || r==2){
            for(int i=0;i<r;i++){
                for(int j=0;j<i+1;j++){
                    res[i].push_back(1);
                }
            }
            return res;
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<i+1;j++){
                 res[i].push_back(1);
            }
        }
        for(int i=2;i<r;i++){
            vector <int> prev=res[i-1];
            vector <int> temp;
            temp.push_back(1);
            for(int j=1;j<prev.size();j++){
                int sum=prev[j-1]+prev[j];
                temp.push_back(sum);
            }
            temp.push_back(1);
            res[i]=temp;
        }
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<res[i].size();j++)
        //         cout<<res[i][j]<<" ";
        //     cout<<endl;
        // }
        return res;
    }
};
