// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

// Method 1 - Using Unordered Map
vector <string> findRestaurant(vector <string> &list1, vector <string> &list2) {
        int n1=list1.size();
        int n2=list2.size();
        unordered_map <string,int> ump;
        for(int i=0;i<n1;i++)
            ump[list1[i]]=i+1;

        vector <string> res;
        int minIdx=n1+n2;
        for(int i=0;i<n2;i++){
            if(ump[list2[i]]){
                int sumIdx=ump[list2[i]]-1+i;
                if(sumIdx<minIdx){
                    minIdx=sumIdx;
                    // cout<<list2[i]<<" "<<ump[list2[i]]-1<<" "<<i<<" "<<sumIdx<<endl;
                    if(res.size())
                        res.clear();
                    res.push_back(list2[i]);
                }
                else if(minIdx==sumIdx)
                    res.push_back(list2[i]);
            }
        }
        return res;
}

// OR //

vector<string> findRestaurant(vector <string> &list1, vector <string> &list2) {
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
