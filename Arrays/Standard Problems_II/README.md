### About problems in Standard Problems_II - Contains problems relared to Subarray Sum.

#### All the problems which contains --> (longest subarray with sum = 0 or k) or (count subarrays with sum = 0 or k) are solved using HASH.
     Problem Number: 2,2a,2b,2c,2d (Array contains both Positive and Negative Numbers.)
     
#### Not able to solve 2 problems - HARD
     Longest Subarray with Sum>k -- https://www.geeksforgeeks.org/largest-subarray-having-sum-greater-than-k/
     Longest Subarray with Sum>=0 -- https://www.geeksforgeeks.org/longest-subarray-with-sum-greater-than-equal-to-zero/

#### Rough Code for - Longest Subarray with Sum>k -- https://www.geeksforgeeks.org/largest-subarray-having-sum-greater-than-k/ - Not Working
     #include <bits/stdc++.h>
     using namespace std;

     bool compare(const pair<int,int> &a, const pair<int,int> &b){
          if(a.first==b.first)
               return a.second<b.second;

          return a.first<b.first;
     }

     int findIdx(vector <pair<int,int>> &preSum, int n, int x){
          int l = 0;
          int h = n - 1;
          int mid;

          int ans = -1;
         cout<<"findIdx"<<endl;
          while(l<=h) {
               mid=(l+h)/2;
               if(preSum[mid].first>x) {
                   cout<<preSum[mid].first<<" ";
                    ans=mid;
                    l=mid+1;
               }
               else
                    h=mid-1;
          }
         cout<<endl;
          return ans;
     }

     // Function to find largest subarray having sum
     // greater than or equal to k.
     int largestSub(int arr[], int n, int k){
          int maxLen=0;
          vector <pair<int,int>> preSum;
          int currSum=0;

          for(int i=0;i<n;i++){
               currSum+=arr[i];
               preSum.push_back({currSum,i});
          }

         cout<<"preSum:"<<endl;
         for(int i=0;i<n;i++)
             cout<<preSum[i].first<<" "<<preSum[i].second<<endl;
         cout<<endl;
          sort(preSum.begin(),preSum.end(),compare);
          cout<<"sort preSum:"<<endl;
         for(int i=0;i<n;i++)
             cout<<preSum[i].first<<" "<<preSum[i].second<<endl;
         cout<<endl;

          // Update minimum index in minIdx array.
          int minIdx[n];
          minIdx[0] = preSum[0].second;
          for(int i=1;i<n;i++)
               minIdx[i]=min(minIdx[i-1],preSum[i].second);
          cout<<"minIdx:"<<endl;
          for(int i=0;i<n;i++)
              cout<<minIdx[i]<<" ";
          cout<<endl;

          currSum=0;
          for(int i=0;i<n;i++) {
               currSum+=arr[i];
               // If sum is greater than k, then answer is i+1.
               if(currSum>k)
                    maxLen=i+1;
               // If the sum is less than or equal to k, then
               // find if there is a prefix array having sum
               // that needs to be added to the current sum to
               // make its value greater than k. If yes, then
               // compare the length of updated subarray with
               // maximum length found so far.
               // Now, k>=currSum
               // i-----------j---------n-1
               // <--currSum-->
               // <-----------k---------->
               // Now, we need some x to add into the currSum to make it equal to k;
               // currSum + x == k 
               // As, need currSum>k, so we will find value greater than x --> (val>x)
               else {
                   int x=k-currSum;
                   cout<<"x: "<<x<<endl;
                    int idx=findIdx(preSum,n,x);
                    if(idx!=-1 && minIdx[idx]<i)
                         maxLen=max(maxLen,i-minIdx[idx]);
               }
          }
          return maxLen;
     }

     // Driver code.
     int main(){
          int arr[] = { -2, 1, 6, -3 };
          int n = sizeof(arr) / sizeof(arr[0]);
          int k = 5;
          cout << largestSub(arr, n, k);
          return 0;
     }

