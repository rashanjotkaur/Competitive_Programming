// https://leetcode.com/problems/kth-largest-element-in-a-stream/

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
