// https://leetcode.com/problems/distribute-candies/


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set <int> candy;
        for(int i=0;i<candyType.size();i++)
            candy.insert(candyType[i]);
        int diffCandy=candy.size();
        int totalCandy=candyType.size();
        int eatable=totalCandy/2;
        // cout<<"diff "<<diffCandy<<"  total "<<totalCandy<<"  eatable "<<eatable<<endl;
        if(diffCandy<eatable)
            return diffCandy;
        return eatable;
    }
};
