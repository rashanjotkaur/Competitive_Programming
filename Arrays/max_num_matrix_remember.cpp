// https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> ump;
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int y=x+1;   //y-x=1(diff)
            if(ump.find(y)!=ump.end())
                maxi=max(maxi,ump[x]+ump[y]);
        }
        return maxi;
    }
};
