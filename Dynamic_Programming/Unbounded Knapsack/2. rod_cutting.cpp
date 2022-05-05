// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#

// Similar to unbounded knapsack
// Given: n=8
// len:   1 2 3 4  5  6  7  8
// price: 1 5 8 9 10 17 17 20

// We have to maximize the price, by making length = 8
// Suppose we are using len=2, then we can use it upto any number of times.
// For each piece of length --> We have infinite supply

// Method 1 - Preferred
class Solution{
  public:
    int cutRod(int price[], int n) {
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j)
                    dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};


// Method 2
using namespace std;
int unbounded_knapsack(int len[],int price[],int n,int l){
    int dp[n+1][l+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=1;j<=l;j++)
        dp[0][j]=price[j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l;j++){
            if(len[i-1]<=j)
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][l];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int price[n],len[n];
        for(int i=0;i<n;i++){
            cin>>price[i];
            len[i]=i+1;
        }
        cout<<unbounded_knapsack(len,price,n,n)<<endl;
    }
    return 0;
}
