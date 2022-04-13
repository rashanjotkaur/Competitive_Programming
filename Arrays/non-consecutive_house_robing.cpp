// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

int FindMaxSum(int arr[], int n){
  long exc=0;
  long inc=arr[0];
  for(int i=1;i<n;i++){
    long exc_new=max(inc,exc);
    inc=exc+arr[i];
    exc=exc_new;
  }
  return max(inc,exc);
}
