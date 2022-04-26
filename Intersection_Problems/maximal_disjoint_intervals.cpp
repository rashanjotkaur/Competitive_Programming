// https://www.geeksforgeeks.org/maximal-disjoint-intervals/

// Given a set of N intervals, the task is to find the maximal set of mutually disjoint intervals. 
// Two intervals [i, j] & [k, l] are said to be disjoint if they do not have any point in common. 

class Solution {
public:
    bool static sortbysec(const pair<int,int> &a, const pair<int,int> &b){
        if(a.second==b.second)
            return a.first<b.first;
       return a.second<b.second;
    }
    int maxNonOverlapIntervals(vector <vector<int>> &intervals) {
        int n=intervals.size();
        vector <pair<int,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back(make_pair(intervals[i][0],intervals[i][1]));
        sort(vec.begin(),vec.end(),sortbysec);
        
        int nonOverlapCount=1;
        int l1,r1,r0;
        r0=vec[0].second;
        for(int i=1;i<n;i++){
            l1=vec[i].first;
            r1=vec[i].second;
            if(l1>=r0){
                nonOverlapCount++;
                r0=r1;
            }
        }
        return nonOverlapCount;
    }
};
