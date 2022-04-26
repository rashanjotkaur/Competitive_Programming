// https://leetcode.com/problems/merge-intervals/

// To merge intervals, we sort in ascending order
// Input
// 2 3
// 1 6
// 6 7
// 4 5
// 8 9

class Solution {
public:
    vector<vector<int>> merge(vector <vector<int>> &intervals) {
        int n=intervals.size();
        vector <pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(intervals[i][0],intervals[i][1]));
        
        sort(v.begin(),v.end());
        // for(int i=0;i<n;i++)
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        
        vector <vector<int>> res;
        int mini=v[0].first;
        int maxi=v[0].second;
        for(int i=1;i<n;i++){
            int l=v[i].first;
            int r=v[i].second;
            if(mini<=l && maxi>=r)
                continue;
            if(l<=maxi){
                maxi=r;
            }
            else{
                vector <int> temp(2);
                temp[0]=mini;
                temp[1]=maxi;
                res.push_back(temp);
                mini=l;
                maxi=r;
            }
        }
        vector <int> temp(2);
        temp[0]=mini;
        temp[1]=maxi;
        res.push_back(temp);
        return res;
    }
};
