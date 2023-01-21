// https://leetcode.com/problems/pascals-triangle/

// Method 1: Preferred
vector <vector<int>> generate(int n) {
        vector <vector<int>> dp(n);
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
            dp[i][0]=1;
            dp[i][i]=1;
            for(int j=1;j<i;j++)
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
        return dp;
}


// Method 2: 
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
