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



// Method 2 - O(nlog(n) + mlog(m))
// Algorithm
// 1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 
// 2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively
//     if arr1[i] is less than arr2[j]
//         increment i
//     else
//         swap the arr2[j] and arr1[k]
//         increment j and decrement k
// 3) Sort both arr1 and arr2 

void merge(long long arr1[], long long arr2[], int n, int m) { 
            // n = 4, arr1[] = [1 3 5 7]   --> i
            // m = 3, arr2[] = [0 2 4] --> j
            int i=0,j=0,k=n-1;
            while(i<=k && j<m){
                if(arr1[i]<arr2[j])
                    i++;
                else{
                    swap(arr1[k],arr2[j]);
                    k--;
                    j++;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
} 

// Time Complexity: The time complexity while traversing the arrays in while loop is O(n+m) in worst case and sorting is O(nlog(n) + mlog(m)). 
// So overall time complexity of the code becomes O((n+m)log(n+m)).


// Method 3 - Prefer method2 over this
// Algorithm:
// 1) Initialize i with 0
// 2) Iterate while loop until last element of array 1 is greater than first element of array 2
//           if arr1[i] greater than first element of arr2
//               swap arr1[i] with arr2[0]
//               sort arr2
//           incrementing i 
void merge(long long arr1[], long long arr2[], int n, int m) { 
            // n = 4, arr1[] = [1 3 5 7]   --> i
            // m = 3, arr2[] = [0 2 4] --> j
            int i=0;
            while(arr1[n-1]>arr2[0]){
               if(arr1[i]>arr2[0]){
                   swap(arr1[i],arr2[0]);
                   sort(arr2,arr2+m);
               }
               i++;
            }
}


// Method 4 - O((n+m)*log(n+m)) - Best Method
// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
class solution{
     public:
        //Function to merge the arrays.
        int nextGap(int total){
            if(total<=1)
                return 0;
            return total/2 + total%2;
        }
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            // n = 4, arr1[] = [1 3 5 7]   --> i
            // m = 3, arr2[] = [0 2 4] --> j
            int i, j, gap = n + m;
            for(gap=nextGap(gap); gap>0; gap=nextGap(gap)){
                // comparing elements in the first array.
                for(i = 0; i + gap < n; i++)
                    if (arr1[i] > arr1[i + gap])
                        swap(arr1[i], arr1[i + gap]);
         
                int x;
                if(gap>n)
                    x=gap-n;
                else
                    x=0;
                    
                // comparing elements in both arrays.
                j=x;
                while(i<n && j<m){
                    if (arr1[i] > arr2[j])
                        swap(arr1[i], arr2[j]);
                    i++;
                    j++;
                }
         
                if (j < m) {
                    // comparing elements in the second array.
                    for (j = 0; j + gap < m; j++)
                        if (arr2[j] > arr2[j + gap])
                            swap(arr2[j], arr2[j + gap]);
                }
            }
        } 
};
