// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& vec, int val) {
        int idx=0;
        int n=vec.size();
        for(int i=0;i<n;i++){
            if(vec[i]!=val){
                int temp=vec[i];
                vec[idx]=temp;
                idx++;
            }
        }
        return idx;
    }
};
