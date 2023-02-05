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


// OR

class Solution{
    public:
    //Function to insert heap.
    priority_queue <int> pq1;
    priority_queue <int,vector<int>,greater<int>> pq2;
    void insertHeap(int &x){
        if(pq1.empty() || pq1.top()>x)
            pq1.push(x);
        else 
            pq2.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps(){
        if(pq1.size()>pq2.size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq2.size()>pq1.size()+1){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    //Function to return Median.
    double getMedian(){
        if(pq1.size()==pq2.size())
            return (double)(pq1.top()+pq2.top())/2.0;
        else
            return pq1.size()>pq2.size()?pq1.top():pq2.top();
    }
};
    

// Method 1: Using Insertion Sort Algo
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Approach: 
// 1. If we can sort the data as it appears, we can easily locate the median element. 
// 2. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, 
//    the first i elements of the array are sorted. The insertion sort doesn’t depend on future data to sort data input till that point. 
// 3. In other words, insertion sort considers data sorted so far while inserting the next element. 
// 4. This is the key part of insertion sort that makes it an online algorithm.

    
#include <bits/stdc++.h>
using namespace std;

double insertionSort(vector <int> &vec, int x){
    vec.push_back(x);
    int n=vec.size();
    int key=vec[n-1];
    int i=n-2;
    while(i>=0 && vec[i]>key){
        vec[i+1]=vec[i];
        i--;
    }
    vec[i+1]=key;
    if(n%2)
        return vec[n/2];
    return (double)(vec[(n/2)-1]+vec[n/2])/2.0;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n;
	    vector <int> vec;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        cout<<insertionSort(vec,x)<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}    
