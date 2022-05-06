// 


// Method 1 - Recursion - TLE
class Solution {
public:
    int maximum(int a,int b,int c){
        int max1=max(a,b);
        int max2=max(max1,c);
        return max2;
    }
    int maxProd(int n){
        if(n==0 || n==1)
            return 0;
        int maxVal=0;
        for(int j=1;j<n;j++)
            maxVal=maximum(maxVal,j*(n-j),j*maxProd(n-j));
        return maxVal;
    }
    int integerBreak(int n) {
        return maxProd(n);
    }
};


// Method 2 - Dynamic Programming
class Solution {
public:
    int maximum(int a,int b,int c){
        int max1=max(a,b);
        int max2=max(max1,c);
        return max2;
    }
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        for(int i=1;i<=n;i++){
            int maxVal=0;
            for(int j=1;j<=i;j++)
                maxVal=maximum(maxVal,j*(i-j),j*dp[i-j]);
            dp[i]=maxVal;
        }
        return dp[n];
    }
};


// Method 3 - Tricky Solution
// n=2 --> 1+1 --> 1
// n=3 --> 2+1 --> 2
// n=4 --> 2+2 --> 4
// n=5 --> 3+2 --> 6
// n=6 --> 3+3 --> 9
// n=7 --> 3+4 --> 12
// n=8 --> 3+3+2 --> 18
// n=9 --> 3+3+3 --> 27
// n=10 --> 3+3+4 --> 36
// n=11 --> 3+3+3+2 --> 54
// If we see some examples of this problem, we can easily observe following pattern. 
// The maximum product can be obtained be repeatedly cutting parts of size 3 while size is greater than 4, 
// Keeping the last part as size of 2 or 3 or 4. For example, n = 10, the maximum product is obtained by 3, 3, 4. 
// For n = 11, the maximum product is obtained by 3, 3, 3, 2. 
 
class Solution {
public:
    int integerBreak(int n) {
        if(n==2 || n==3)
            return n-1;
        int res=1;
        while(n>4){
            n=n-3;
            res=res*3;
        }
        return n*res;
    }
};
