// https://practice.geeksforgeeks.org/problems/maximum-index3307/1/#

// arr[j]>arr[i] & max (j-i)

// Method 1: O(n) Efficient Solution
int maxIndexDiff(int arr[], int n) {
        vector <int> LMin(n); 
        vector <int> RMax(n);
        
        LMin[0] = arr[0];
        for(int i=1;i<n;i++)
            LMin[i] = min(arr[i],LMin[i-1]);
     
        RMax[n-1] = arr[n-1];
        for(int j=n-2;j>=0;j--)
            RMax[j] = max(arr[j],RMax[j+1]);
     
        int i=0,j=0,maxDiff=0;
        while(j<n && i<n) {
            if(LMin[i] <= RMax[j]){
                maxDiff = max(maxDiff, j-i);
                j++;
            }
            else
                i++;
        }
     
        return maxDiff;
}


// Method 2: O(n^2)
int maxIndexDiff(int arr[], int n) {
        int maxDiff=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(arr[j]>=arr[i] && maxDiff<j-i)
                    maxDiff=j-i;
            }
        } 
        return maxDiff;
}
