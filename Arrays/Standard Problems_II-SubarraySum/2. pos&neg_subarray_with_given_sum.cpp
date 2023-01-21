// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

// Input Array contains both Positive & Negative Integers...

// Using Hash is best method to solve this
vector <int> findSubarray(vector <int> nums, int n, int k){
        unordered_map <int,int> ump;
        vector <int> res;
        long long currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum==k){
                res.push_back(1);
                res.push_back(i+1);
                return res;
            }
            if(ump.find(currSum)==ump.end())
                ump[currSum]=i;
            int x=currSum-k;
            if(ump.find(x)!=ump.end()){
                res.push_back(ump[x]+1+1);
                res.push_back(i+1);
                return res;
            }
        }
        if(res.size()==0)
            res.push_back(-1);
        return res;
}
