// https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/#

// Method 1: Naive Approach
int max_sum(int arr[],int n){
    int maxSum=0;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=0;j<n;j++)
            currSum+=((i+j)%n)*arr[j];
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}


// Method 2: O(n)
int max_sum(int arr[],int n){
    int currSum=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        currSum+=i*arr[i];
    }
    int maxSum=currSum;
    for(int j=1;j<n;j++){
        // r1=r0+sum-n*arr[n-1];
        currSum=currSum+sum-n*arr[n-j];
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}
