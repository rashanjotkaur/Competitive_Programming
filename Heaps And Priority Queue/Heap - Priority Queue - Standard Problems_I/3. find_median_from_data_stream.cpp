// Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

// Method 2: Using Priority Queue
// Time Complexity: O(nlogn)
// Auxillary Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

// Using Min & Max Priority Queues
priority_queue <int> smaller; //MaxHeap
priority_queue <int,vector<int>,greater<int>> larger; //MinHeap

double findMedian(int x){
    if((smaller.empty() || smaller.top()>x))
            smaller.push(x);
    else
        larger.push(x);
        
    // Rebalance 
    if(smaller.size()>larger.size()+1){
        larger.push(smaller.top());
        smaller.pop();
    }
    else if(larger.size()>smaller.size()+1){
        smaller.push(larger.top());
        larger.pop();
    }
    
    double median;
    if(smaller.size()==larger.size())
        return smaller.empty()?0:(double)(smaller.top()+larger.top())/2.0;
    else
        return smaller.size()>larger.size()?smaller.top():larger.top();
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            cout<<findMedian(x)<<" ";
        }
        cout<<endl;
    }
	return 0;
}
    

// Method 1: Using Insertion Sort Algo
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Approach: 
// 1. If we can sort the data as it appears, we can easily locate the median element. 
// 2. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, 
//    the first i elements of the array are sorted. The insertion sort doesn’t depend on future data to sort data input till that point. 
// 3. In other words, insertion sort considers data sorted so far while inserting the next element. 
// 4. This is the key part of insertion sort that makes it an online algorithm.
    
    
