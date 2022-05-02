// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    void nextSmallerRight(vector <int> height,vector <int> &nsr,int n){
        stack <int> s; //store indexes
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && height[s.top()]>=height[i])
                s.pop();
            nsr[i]=s.empty()?n:s.top();
            s.push(i);
        }
        // cout<<"nsr"<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<nsr[i]<<" ";
        // cout<<endl;
    }
    void nextSmallerLeft(vector <int> height,vector <int> &nsl,int n){
        stack <int> s; //store indexes
        for(int i=0;i<n;i++){
            while(!s.empty() && height[s.top()]>=height[i])
                s.pop();
            nsl[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        // cout<<"nsl"<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<nsl[i]<<" ";
        // cout<<endl;
    }
    int maxAreaHistogram(vector <int> height){
        int n=height.size();
        vector <int> nsr(n);
        vector <int> nsl(n);
        nextSmallerRight(height,nsr,n);
        nextSmallerLeft(height,nsl,n);
        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=nsr[i]-nsl[i]-1;
            if(width>0){
                int area=width*height[i];
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector <vector<int>> mat(r,vector <int> (c,0));
        for(int j=0;j<c;j++){
            if(matrix[0][j]=='1')
                mat[0][j]=1;
        }
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                    mat[i][j]=mat[i-1][j]+1;
                else
                    mat[i][j]=0;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        int maxRec=0;
        for(int i=0;i<r;i++){
            vector <int> temp=mat[i];
            cout<<"i: "<<i<<endl;
            int rec=maxAreaHistogram(temp);
            cout<<rec<<endl;
            maxRec=max(maxRec,rec);
        }
        return maxRec;
    }
};
