// https://leetcode.com/problems/interval-list-intersections/description/?envType=study-plan&id=algorithm-ii

vector <vector<int>> intervalIntersection(vector <vector<int>>& firstList, vector <vector<int>>& secondList) {
            vector <vector<int>> res;
            int i=0,j=0;
            int fs=firstList.size(),ls=secondList.size();
            while(i<fs && j<ls){
                int x1=firstList[i][0];
                int y1=firstList[i][1];
                int x2=secondList[j][0];
                int y2=secondList[j][1];
                int x=max(x1,x2);
                int y=min(y1,y2);
                if(x<=y){
                    vector <int> temp(2);
                    temp[0]=x;
                    temp[1]=y;
                    res.push_back(temp);
                }
                // Important
                firstList[i][1]>secondList[j][1]?j++:i++;
            }
            return res;
}
