// Kth Largest Element in array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Method 1: Using Min Priority Queue - (For Largest --> Min Priority Queue is used)
int findKthLargest(vector <int> &nums, int k) {
        int n=nums.size();
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.size()==k?pq.top():-1;
}

// Method 2: Using Max Heap
// Func 1: 
int findKthLargest(vector <int> &nums, int k) {
        int n=nums.size();
        // Build Heap
        for(int i=n/2-1;i>=0;i--)
            maxHeapify(nums,i,n);
        k--;
        // Heapify k-1 times after removing the max element
        while(k--){
            nums[0]=nums[n-1];
            nums.pop_back();
            n--;
            maxHeapify(nums,0,n);
        }
        return nums[0];
 }

// Func 2: 
 void maxHeapify(vector <int> &nums, int i, int n){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<n && nums[left]>nums[largest])
            largest=left;
        if(right<n && nums[right]>nums[largest])
            largest=right;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            maxHeapify(nums,largest,n);
        }
 }
    
