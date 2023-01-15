// https://leetcode.com/problems/majority-element/

// Method 1: Preferred - Moore's Voting Algorithm
// Func 1: 
int majorityElement(vector <int> &nums) {
        int n=nums.size();
        int candidate_key=mooreVoting(nums,n);
        return verify(nums,n,candidate_key);
}

// Func 2: 
int mooreVoting(vector <int> nums, int n){
        int maj_idx=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[maj_idx]==nums[i])
                count++;
            else
                count--;
            if(count==0) {
                maj_idx=i;
                count=1;
            }
        }
        return nums[maj_idx];
}

// Func 3: 
int verify(vector <int> nums, int n, int candidate_key){
        int fre=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate_key)
                fre++;
            if(fre>n/2)
                return candidate_key;
        }
        return -1;
}

//  OR  //

// Method 2: Using Sort
// Approach: 
// 1. Given the condition, if any element appear more than n/2 times is called Majority Element.
// 2. Then we know our Mid Element means (n-1/2) is also our Majority Element if satisfied the given condition.
// 3. Simply, return Mid Element.
int majorityElement(vector <int> &nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[(n-1)/2];
}

//  OR  //

// Method 3: Using hash -- Unordered_map
int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            if(ump[nums[i]]>n/2)
                return nums[i];
        }
        return -1;
}

