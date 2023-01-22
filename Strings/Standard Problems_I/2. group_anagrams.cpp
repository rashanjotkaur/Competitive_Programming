// https://leetcode.com/problems/group-anagrams/

// Method 2 - Preferred - Tricky
vector <vector<string>> groupAnagrams(vector <string> &strs) {
        int n=strs.size();
        unordered_map <string, int> ump;
        vector <vector<string>> res;
        for(int i=0;i<n;i++) {
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());

            if(ump.count(sorted)){
                int idx=ump[sorted]; //if already count exists, then it was previously stored at this index in res
                res[idx].push_back(strs[i]);
            }
            else{
                res.push_back({strs[i]});
                int idx=res.size()-1; // idx at which it is stored is (vector size - 1)
                ump[sorted]=idx;
            }
        }
        return res;
}

// Method 1 
vector <vector<string>> groupAnagrams(vector <string> &strs) {
        int n=strs.size();
        unordered_map <string,pair<vector<string>,int>> ump;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            ump[temp].second++;
            ump[temp].first.push_back(strs[i]);
        }
        vector <vector<string>> res;
        for(auto x:ump){
            vector <string> temp=x.second.first;
            sort(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
}
