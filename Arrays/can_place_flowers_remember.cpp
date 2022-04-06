// https://leetcode.com/problems/can-place-flowers/

// Good and Easy Solution

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int flower) {
        int count=0;
        int n=flowerbed.size();
        for(int i=0;i<n;i++){
            if(flowerbed[i]==0){
                int prev = (i==0 || flowerbed[i-1]==0) ? 0 : 1;
                int next = (i==n-1 || flowerbed[i+1]==0) ? 0 : 1;
                if(prev==0 && next==0){
                    count++;
                    flowerbed[i]=1;
                }
            }
        }
        bool ans=count>=flower ? true : false;
        return ans;
    }
};
