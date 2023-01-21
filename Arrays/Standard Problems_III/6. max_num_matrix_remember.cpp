// https://leetcode.com/problems/range-addition-ii/

int maxCount(int m, int n, vector <vector<int>> &ops) {
        int minX=m;
        int minY=n;
        for(int i=0;i<ops.size();i++){
            minX=min(minX,ops[i][0]);
            minY=min(minY,ops[i][1]);
        }
        return minX*minY;
}
