// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// https://practice.geeksforgeeks.org/problems/length-unsorted-subarray3022/1
// Video Explaination: https://www.youtube.com/watch?v=GvAtQOMr8CQ

int findUnsortedSubarray(vector <int> &nums) {
        int n=nums.size();
        int start=-1;
        int end=-1;
        int maxEle=nums[0];
        for(int i=1;i<n;i++){
            int currEle=nums[i];
            if(currEle>=maxEle)
                maxEle=currEle;
            else
                end=i;
        }
        int minEle=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int currEle=nums[i];
            if(currEle<=minEle)
                minEle=currEle;
            else
                start=i;
        }
        return (start==-1 && end==-1)?0:end-start+1;
}
