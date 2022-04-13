// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& vec) {
        int n=vec.size();
        int cmp=vec[0];
        int idx=1;
        for(int i=1;i<n;i++){
            if(cmp!=vec[i]){
                cmp=vec[i];
                vec[idx]=cmp;
                idx++;
            }
        }
        return idx;
    }
};
