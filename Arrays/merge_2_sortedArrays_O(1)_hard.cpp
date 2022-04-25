// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#
// GFG Solutions: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/


// Method 1 - O(n*m)
// Algorithm: 
// Iterate through every element of arr2[] starting from last element. Do following for every element arr2[j]
//     a) Store last element of arr1[]: last = arr1[n-1]
//     b) Loop from last element of arr2[] while element arr2[j] < arr1[i]
//           arr1[i+1] = arr1[i] // Move element one position ahead
//           i--
//     c) If any element of arr1[] was moved i.e. (i != n-1)
//           arr1[i+1] = arr2[j] 
//           arr2[j] = last

void merge(long long arr1[], long long arr2[], int n, int m) { 
     // n = 4, arr1[] = [1 3 5 7]   --> i
     // m = 3, arr2[] = [0 2 4] --> j
     for(int j=m-1;j>=0;j--){
         int last=arr1[n-1];
         int i=n-2;
         while(i>=0 && arr2[j]<arr1[i]){
              arr1[i+1]=arr1[i];
              i--;
         }
         if(i!=n-2 || last>arr2[j]){
              arr1[i+1]=arr2[j];
              arr2[j]=last;
         }
     }
} 



