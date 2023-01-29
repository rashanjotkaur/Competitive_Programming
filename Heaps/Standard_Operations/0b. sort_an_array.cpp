// Sort an Array
// https://leetcode.com/problems/sort-an-array/description/

// Func 1:
vector<int> sortArray(vector <int> &nums) {
        buildHeap(nums);
        int heapSize=nums.size();
        while(heapSize>=2){
            swap(nums[0],nums[heapSize-1]);
            heapSize--;
            maxHeapify(nums,0,heapSize);
        }
        return nums;
}

// Func 2: 
void buildHeap(vector <int> &nums){
        int n=nums.size();
        for(int i=(n/2)-1;i>=0;i--)
            maxHeapify(nums,i,n);
}

// Func 3: 
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
