// Same as question 1, but here we have two arrays.
// maximize the value of expression: |A[i]-A[j]| + |B[i]-B[j]| + |i-j|
// Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/

class Solution {
public:
    int check(vector <int> vec,int n){
        int maxp=INT_MIN;
        int minp=INT_MAX;
        int maxs=INT_MIN;
        int mins=INT_MAX;
        for(int i=0;i<n;i++){
            maxp=max(maxp,vec[i]+i);
            minp=min(minp,vec[i]+i);
            maxs=max(maxs,vec[i]-i);
            mins=min(mins,vec[i]-i);
        }
        int diffp=abs(maxp-minp);
        int diffs=abs(maxs-mins);
        return max(diffp,diffs);
    }
    int maxAbsValExpr(vector<int>& vec1, vector<int>& vec2) {
        int n=vec1.size();
        vector <int> add(n);
        vector <int> sub(n);
        for(int i=0;i<n;i++){
            add[i]=vec1[i]+vec2[i];
            sub[i]=vec1[i]-vec2[i];
        }
        int addition=check(add,n);
        int subtraction=check(sub,n);
        return max(addition,subtraction);
    }
};
