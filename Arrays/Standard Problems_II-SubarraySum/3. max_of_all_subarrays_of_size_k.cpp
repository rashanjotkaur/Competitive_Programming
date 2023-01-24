// Sliding Window Maximum - Maximum of all Subarrays of Size k.
// https://leetcode.com/problems/sliding-window-maximum/
// Video Explaination - https://takeuforward.org/data-structure/sliding-window-maximum/

// Method - Using Dequeue
vector <int> maxSlidingWindow(vector <int> &nums, int k) {
        int n=nums.size();
        deque <int> dq;
        vector <int> res;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && nums[i]>nums[dq.back()])
                 dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                res.push_back(nums[dq.front()]);
        }
        return res;
}
