// Activity Selection Problem | Greedy Algo-1
// Link - https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
// Problem Link - https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// Method 1 - Using sorting
// Approach: 
// 1. It might not be possible to complete all the activities, since their timings can collapse.
// 2. Two activities, say i and j:
//      -> si - fi
//      -> sj - fj
//    These are said to be non-conflicting if the starting time of these activities are greater than finish time of other activities.
//      -> si >= fj or sj >= fi where si and sj denote the starting time and fi and fj refer to the finishing time of the activities.
// 3. Greedy approach can be used to find the solution since we want to "maximize the count of activities that can be executed". 
//    This approach will greedily choose an activity with earliest finish time at every step, thus yielding an optimal solution.

// Since, we need starting always greater than ending times, so we have to sort it by ending times.
int activitySelection(vector<int> start, vector<int> end, int n){
        vector <pair<int,int>> act;
        for(int i=0;i<n;i++)
            act.push_back({end[i],start[i]});
        sort(act.begin(),act.end());
        for(int i=0;i<n;i++){
            int temp=act[i].first;
            act[i].first=act[i].second;
            act[i].second=temp;
        }
        int count=1;
        int prevTask=act[0].second;
        for(int i=1;i<n;i++){
            int currTask=act[i].first;
            if(currTask>prevTask){
                count++;
                prevTask=act[i].second;
            }
        }
        return count;
}


// Note: 
// 1. We can use sortbysec here, but it is not working in this.
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
// 2. Usually equal start & end is also counted 
// 1 2
// 2 4
// Then the person can do two task, but here equal is not counted.


