// https://leetcode.com/problems/distribute-candies/

// Method 1: By Removing the Duplicates
// Approach: 
// 1. Sort the vector.
// 2. Remove the duplicates - Inplace removal
class Solution {
public:
    int distributeCandies(vector <int> &candyType) {
        int n=candyType.size();
        sort(candyType.begin(),candyType.end());
        int comp=candyType[0];
        int idx=1;
        for(int i=1;i<n;i++){
            if(comp!=candyType[i]){
                comp=candyType[i];
                candyType[idx]=comp;
                idx++;
            }
        }
        return (idx<n/2)?idx:n/2;
    }
};

// Method 2: By using Unordered Set
class Solution {
public:
    int distributeCandies(vector <int> &candyType) {
        int n=candyType.size();
        unordered_set <int> diffCandies;
        for(int i=0;i<n;i++)
            diffCandies.insert(candyType[i]);
        int typeOfCandies=diffCandies.size();
        return (typeOfCandies<=n/2)?typeOfCandies:n/2;
    }
};
