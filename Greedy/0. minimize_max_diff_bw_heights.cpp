// Minimize the maximum difference between the heights
// Link - https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Method 1 - Tricky and Hard
// Approach: Two Elements ke beech main minimum diff kbb hoga, when they are sorted, x+1 is just greater than x.
// 1. Sort the array
// 2. minDiff=arr[x+1]-arr[x]
// 3. But yeh difference aur bhi kmm kaise ho skhta, if we increase the arr[x] (curr element by k) and decrease the arr[x+1] (next element by k)
// 4. minDiff=abs( (arr[x]+k) - (arr[x+1]-k) )
int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int minDiff=arr[n-1]-arr[0];
        int small=arr[0]+k; // To minimize the diff, next ko inc krte, prev ko dec krte.
        int large=arr[n-1]-k;
        for(int i=0;i<n-1;i++){
            // To minimize the diff, next ko inc krte, prev ko dec krte.
            int currAdd=max(large,arr[i]+k);
            int nextSub=min(small,arr[i+1]-k);
            
            if(nextSub<0)
                continue;
            minDiff=min(minDiff,currAdd-nextSub);
        }
        return minDiff;
}
