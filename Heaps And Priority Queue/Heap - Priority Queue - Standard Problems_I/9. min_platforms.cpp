// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Method 3: Using Priority Queue 
int findPlatform(int arr[], int dep[], int n){
        vector <pair<int,int>> time;
    	for(int i=0;i<n;i++)
    	    time.push_back(make_pair(arr[i],dep[i]));
    	sort(time.begin(),time.end());
    	
        priority_queue <int,vector<int>,greater<int>> pq;
        int platforms=1;
        pq.push(time[0].second);
        for(int i=1;i<n;i++){
            if(time[i].first<=pq.top())
                platforms++;
            else
                pq.pop();
            pq.push(time[i].second);
        }
        return platforms;
}

// Method 2: Using Multiset
// Multiset vs Set: 
// 1. In Set, duplicate values are not allowed to get stored. 
// 2. On other hand in case of MultiSet we can store duplicate values. 
int findPlatform(int arr[], int dep[], int n){
    	multiset <pair<int,char>> mset;
    	for(int i=0;i<n;i++)
    	    mset.insert(make_pair(arr[i],'A'));
    	for(int i=0;i<n;i++)
    	    mset.insert(make_pair(dep[i],'D'));
    	int platforms=0;
    	int maxPlatforms=0;
    	for(auto it:mset){
    	    if(it.second=='A')
    	        platforms++;
    	    else if(it.second=='D')
    	        platforms--;
    	    maxPlatforms=max(maxPlatforms,platforms);
    	}
    	return maxPlatforms;
}

// OR

// Using Pair of Vectors
int findPlatform(int arr[], int dep[], int n){
        vector <pair<int,char>> interval;
        for(int i=0;i<n;i++)
            interval.push_back({arr[i],'A'});
        for(int i=0;i<n;i++)
            interval.push_back({dep[i],'D'});
        sort(interval.begin(),interval.end());
        int platforms=0;
        int maxPlatforms=0;
        for(int i=0;i<interval.size();i++){
            if(interval[i].second=='A')
                platforms++;
            else
                platforms--;
            maxPlatforms=max(maxPlatforms,platforms);
        }
        return maxPlatforms;
}


// Method 1: By Sorting and comparing
int findPlatform(int arr[], int dep[], int n){
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int j=0;
        int i=1;
        int platform=1;
        int maxPlatform=0;
        // Similar to merge in merge sort to process all events in sorted order
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            maxPlatform=max(maxPlatform,platform);
        }
        return maxPlatform;
}


