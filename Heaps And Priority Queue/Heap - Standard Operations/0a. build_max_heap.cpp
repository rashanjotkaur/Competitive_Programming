// Go Through Notes for more explaination

// Method 1: Here, we are excluding the leaf nodes as they are single nodes only.
// Number of Leaf Nodes = Number of Internal Nodes + 1
// Leaf Nodes = N/2 to N-1
// Internal Nodes = 0 to N/2-1 

// Func 1: 
void buildHeap(vector <int> &nums){
        int n=nums.size();
        for(int i=(n/2)-1;i>=0;i--)
            maxHeapify(nums,i,n);
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


// Application:
// 1. To sort an array - Convert into Max Heap using MaxHeapify Func --> then swap(arr[0],arr[n-1]) --> Again use MaxHeapify Func.
