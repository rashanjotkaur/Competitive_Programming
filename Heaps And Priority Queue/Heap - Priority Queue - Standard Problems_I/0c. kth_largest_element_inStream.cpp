// Kth largest element in a stream
// Problem Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/
// Leetcode: https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Solution: Using Min Priority Queue
vector <int> kthLargest(int k, int arr[], int n) {
        vector <int> res;
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
                res.push_back(pq.top());
            }
            else if(pq.size()==k)
                res.push_back(pq.top());
            else
                res.push_back(-1);
        }
        return res;
}


// LeetCode Solution
class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq;
    int maxSize;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        maxSize=k;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>maxSize)
            pq.pop();
        return pq.top();
    }
};
