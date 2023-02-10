// Frog Jump
// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// Find the minimum total energy used by frog to reach from 1st stair to the nth stair.

// Method 1: DP solution using Array
int frogJump(int n, vector <int> &h){
    vector <int> dp(n,0);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for (int i = 2; i < n; i++) 
        dp[i] = min((abs(h[i] - h[i - 1]) + dp[i-1]),
                  (abs(h[i] - h[i - 2]) + dp[i-2]));

    return dp[n-1];
}

// Method 2: Space optimization
int frogJump(int n, vector <int> &h){
    int step2=0;   // Taking two steps at a time
    int step1=abs(h[1]-h[0]);   // Taking one step at a time
    for (int i = 2; i < n; i++) {
        int currStep = min((abs(h[i] - h[i - 1]) + step1),(abs(h[i] - h[i - 2]) + step2));
        step2=step1;
        step1=currStep;
    }
    return step1;
}
