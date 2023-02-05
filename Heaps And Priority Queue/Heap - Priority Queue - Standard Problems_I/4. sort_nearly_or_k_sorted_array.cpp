// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// Problem Link: https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Method 1: Using priority queue to store k elements
// Approach: 
// 1. Create a Min Heap of size K+1 with the first K+1 elements. 
// 2. We are creating a heap of size K as the element can be at most K distance from its index in a sorted array. 
// 3. One by one remove the min element from the heap, put it in the result array, and add a new element to the heap from the remaining elements.
vector <int> nearlySorted(int arr[], int n, int k){
        vector <int> res;
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()==k+1){  // k away includes k+1 elements.
                res.push_back(pq.top());
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
}

// OR 

// Method 2: Using Insertion Sort - Gives TLE
// Time Complexity: O(N*K)
// Space Complexity: O(1)
vector <int> nearlySorted(int arr[], int n, int k){
        for(int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        vector <int> res;
        for(int i=0;i<n;i++)
            res.push_back(arr[i]);
        return res;
}
