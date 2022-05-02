// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
    
        int maxLeft[n];
        maxLeft[0]=height[0];
        for(int i=1;i<n;i++)
            maxLeft[i]=max(height[i],maxLeft[i-1]);
        
        int maxRight[n];
        maxRight[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            maxRight[i]=max(height[i],maxRight[i+1]);
        
        int water[n];
        for(int i=0;i<n;i++)
            water[i]=min(maxLeft[i],maxRight[i])-height[i];
        
        int rainWater=0;
        for(int i=0;i<n;i++)
            rainWater+=water[i];
        
        return rainWater;     
    }
};
