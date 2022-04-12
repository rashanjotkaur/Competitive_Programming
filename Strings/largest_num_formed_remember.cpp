// Largest Number formed from an array..

// https://leetcode.com/problems/largest-number/

class Solution {
public:
     static bool cmp(string a, string b){
        string ab=a.append(b);
        string ba=b.append(a);
        return ab>ba;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector <string> vec;
        int count=0;
        string res="";
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                count++;
            vec.push_back(to_string(nums[i]));
        }
        if(count==n){
            res+="0";
            return res;
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();i++){
            res+=vec[i];
        }
        return res;
    }
};
