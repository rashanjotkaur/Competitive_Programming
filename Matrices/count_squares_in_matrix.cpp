// https://practice.geeksforgeeks.org/problems/squares-in-a-matrix5716/1/
// https://leetcode.com/discuss/interview-question/370988/Amazon-or-Phone-Screen-or-Count-Number-of-Squares-in-a-grid/334035

// Remember
class Solution {
  public:
    long long squaresInMatrix(int m, int n) {
        int side=min(m,n);
        long long int countSquares=0;
        for(int i=0;i<side;i++)
            countSquares+=(m-i)*(n-i);
        return countSquares;
    }
};

