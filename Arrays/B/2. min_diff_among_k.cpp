// Minimum Difference among K
// https://www.geeksforgeeks.org/k-numbers-difference-maximum-minimum-k-number-minimized/
// Problem Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-difference-among-k5805/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Method 1: Using Heaps & Priority Queue

// Method 2: By Sorting
int minDiff(int arr[], int n, int k){
        sort(arr,arr+n);
        int minDiff=INT_MAX;
        for(int i=0;i<n-k+1;i++)
            minDiff=min(minDiff,arr[i+k-1]-arr[i]);
        return minDiff;
}
