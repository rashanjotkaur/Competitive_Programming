// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    #define ll long long int
    void nextSmallerLeft(vector <int> &nsl, vector <int> heights,ll n){
        stack <int> s; //store indexes
        for(ll i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            nsl[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        // for(ll i=0;i<n;i++)
        //     cout<<nsl[i]<<" ";
        // cout<<endl;
    }
    void nextSmallerRight(vector <int> &nsr, vector <int> heights,ll n){
        stack <int> s;
        for(ll i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            nsr[i]=s.empty()?n:s.top();
            s.push(i);
        }
        // for(ll i=0;i<n;i++)
        //     cout<<nsr[i]<<" ";
        // cout<<endl;
    }
    int largestRectangleArea(vector<int>& heights) {                   
        ll n=heights.size();
        vector <int> nsl(n);
        vector <int> nsr(n);
        nextSmallerLeft(nsl,heights,n);
        nextSmallerRight(nsr,heights,n);
        ll maxArea=0;
        for(ll i=0;i<n;i++){
            ll width=nsr[i]-nsl[i]-1;
            if(width>0){
                ll area=width*heights[i];
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};
