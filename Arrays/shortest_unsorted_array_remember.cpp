// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector <int> &num) {
        int n=num.size();
        int s=-1,e=-1;
        for(int i=0;i<n-1;i++){
            if(num[i]>num[i+1]){
                s=i;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(num[i]<num[i-1]){
                e=i;
                break;
            }
        }
        if(s==-1 || e==-1)
            return 0;
        
        int mini=num[s];
        int maxi=num[s];
        for(int i=s+1;i<=e;i++){
            if(num[i]<mini)
                mini=num[i];
            if(num[i]>maxi)
                maxi=num[i];
        }
        for(int i=0;i<s;i++){
            if(num[i]>mini){
                s=i;
                break;
            }
        }
        for(int i=n-1;i>e;i--){
            if(num[i]<maxi){
                e=i;
                break;
            }
        }
        return e-s+1;
    }
};
