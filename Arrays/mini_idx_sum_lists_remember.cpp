// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string,int> ump;
        for(int i=0;i<list1.size();i++)
            ump[list1[i]]=i;
        
        int minIdx=INT_MAX;
        vector <string> res;
        for(int i=0;i<list2.size();i++){
            if(ump.find(list2[i])!=ump.end() && ump[list2[i]]+i<=minIdx){
                if(ump[list2[i]]+i!=minIdx)  //means ump[list2[i]]+i<minIdx, so clear whatever is present till now in vector, because we will include this.
                    res.clear();
                
                res.push_back(list2[i]); //for both cases either less than or equal to ump[list2[i]]+i<minIdx
                minIdx=ump[list2[i]]+i;
            }
        }
        return res;
    }
};
