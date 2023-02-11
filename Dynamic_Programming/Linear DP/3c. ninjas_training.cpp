// Ninja’s Training
// Striver Solution: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
// Problem Link: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// Method 2: Memoization - Storing the values while RECURSION 
// This is also giving TLE
int maxPoints(int day, int last, vector <vector<int>> task, 
vector <vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi=max(maxi,task[0][i]);
        }
        return dp[0][last]=maxi;
    }


    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int currActivity;
            if(dp[day-1][i]!=-1)
                currActivity=dp[day-1][i]+task[day][i];
            else
                currActivity=maxPoints(day-1,i,task,dp)+task[day][i];
            maxi = max(maxi,currActivity);
        }
    }
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector <vector <int>> &points){
    vector <vector<int>> dp(n,vector<int>(3,-1));
    return maxPoints(n-1,3,points,dp);
}



// Method 1: Using Recursion - TLE
int maxPoints(int day, int last, vector <vector<int>> task){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi=max(maxi,task[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if (i != last) {
            int currActivity=maxPoints(day-1,i,task)+task[day][i];
            maxi = max(maxi,currActivity);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector <vector <int>> &points){
    return maxPoints(n-1,3,points);
}
