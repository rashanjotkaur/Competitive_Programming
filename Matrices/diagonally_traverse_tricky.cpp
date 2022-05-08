// Good Solution - Must Remember
// https://leetcode.com/problems/diagonal-traverse-ii/

// Algorithm:
// Step 1: Number of diagonals = rows+cols-1
// Step 2: We are storing at (i+j) in map, to get diagonal elements
// Step 3: 0 --> 1
//         1 --> 2, 4
//         2 --> 3, 5, 7
//         3 --> 6, 8
//         4 --> 9
// Step 4: Now, we just have to insert the elements into vector after reversing.
  
class Solution {
public:
    vector<int> findDiagonalOrder(vector <vector<int>> &nums) {
        int rows=nums.size();
        unordered_map <int,vector<int>> ump;
        for(int i=0;i<rows;i++){
            for(int j=0;j<nums[i].size();j++)
                ump[i+j].push_back(nums[i][j]);
        }
        vector <int> res;
        for(int i=0;i<ump.size();i++){
            vector <int> temp=ump[i];
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++)
                res.push_back(temp[j]);
        }
        return res;
    }
};
