// https://leetcode.com/problems/remove-element/

int removeElement(vector <int> &nums, int val) {
        int n=nums.size();
        int comp=val;
        int idx=0;
        for(int i=0;i<n;i++){
            if(comp!=nums[i]){
                nums[idx]=nums[i];
                idx++;
            }
        }
        return idx;
}
