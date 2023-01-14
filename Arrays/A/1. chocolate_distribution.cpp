//  https://www.geeksforgeeks.org/chocolate-distribution-problem/
//  Problem: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    int min(int a,int b){
        return a<b?a:b;
    }
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int diff=INT_MAX;
        for(int i=0;i<n-m+1;i++)
            diff=min(diff,abs(a[i]-a[i+m-1]));
        return diff;
    }   
};
