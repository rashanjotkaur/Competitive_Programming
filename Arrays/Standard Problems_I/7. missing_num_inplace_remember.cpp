// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Steps:
// 1. Check if: already at its correct position
// 2. Check if: its duplicate
// 3. Check if: not at correct position

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> res;
        nums.insert(nums.begin(),0);
        int n=nums.size();
        cout<<n<<endl;
        int i=0;
        while(i<n){
            //already at its correct position
            if(nums[i]==i || nums[i]==-1)
                i++;
            //duplicate
            else if(nums[i]==nums[nums[i]]){
                nums[i]=-1;
                i++;
            }
            //not at correct position
            else{
                swap(nums[i],nums[nums[i]]);
            }
        }
            
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
            if(nums[i]==-1)
                res.push_back(i);
        }
        return res;
    }
};
