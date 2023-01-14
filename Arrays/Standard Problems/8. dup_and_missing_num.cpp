// https://leetcode.com/problems/set-mismatch/
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// One of the numbers in array got duplicated to another number in the array, which results in repetition of one number and loss of another number.
// Find the duplicate and missing number.

// Good Question - Medium

// Method 1 - Preferred
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {       
        nums.insert(nums.begin(),0);
        int n=nums.size();
        int dup=-1,mis=-1;
        for(int i=0;i<n;i++){
            while(nums[i]!=i && nums[i]!=nums[nums[i]])
                swap(nums[i],nums[nums[i]]);
            
            if(nums[i]!=i && nums[i]==nums[nums[i]])
                dup=nums[i];
            
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                mis=i;
                break;
            }
        }
        vector <int> res;
        res.push_back(dup);
        res.push_back(mis);
        return res;
    }
};


// Method 2 - By Removing Duplicates
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int dup=-1;
        int mis=-1;
        int idx=1;
        int comp=nums[0];
        for(int i=1;i<n;i++){
            if(comp!=nums[i]){
                comp=nums[i];
                nums[idx]=comp;
                idx++;
            }
            else
                dup=comp;
        } 
        int p=1;
        int q=0;
        while(p<=n && q<idx){
            if(p!=nums[q]){
                mis=p;
                break;
            }
            p++;
            q++;
        }
        if(mis==-1)
            mis=n;
        vector <int> res;
        res.push_back(dup);
        res.push_back(mis);
        return res;
    }
};
