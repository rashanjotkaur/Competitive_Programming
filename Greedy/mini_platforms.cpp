// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/#
// Method 1,2,3: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// Method 4: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/

// Method 1 - Using Priority Queue. 
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
int findPlatform(int arr[], int dep[], int n){
    	vector <pair<int,int>> time;
    	for(int i=0;i<n;i++)
    	    time.push_back(make_pair(arr[i],dep[i]));
    	sort(time.begin(),time.end());
    	
    	priority_queue <int, vector <int>, greater <int>> pq;
    	int count=1;
    	pq.push(time[0].second);
    	for(int i=1;i<n;i++){
    	    if(pq.top()>=time[i].first)
    	        count++;
    	    else
    	        pq.pop();
    	    pq.push(time[i].second);
    	}
      return count;
}

// Method 2 - Vector of pairs.
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
int findPlatform(int arr[], int dep[], int n){
    	vector <pair<int,char>> interval;
    	for(int i=0;i<n;i++)
    	    interval.push_back(make_pair(arr[i],'A'));
    	for(int i=0;i<n;i++)
    	    interval.push_back(make_pair(dep[i],'D'));
    	    
    	sort(interval.begin(),interval.end());
    // 	for(int i=0;i<interval.size();i++)
    // 	    cout<<interval[i].first<<"  "<<interval[i].second<<endl;
    	int count=0;
    	int maxCount=INT_MIN;
    	for(int i=0;i<interval.size();i++){
    	    if(interval[i].second=='A')
    	        count++;
    	    else if(interval[i].second=='D')
    	        count--;
    	    maxCount=max(maxCount,count);
    	}
    	return maxCount;
}



// Method 3 - Sorting both arrival and departure vectors.
// Time Complexity: O(N * log N), One traversal O(n) of both the array is needed after sorting O(N * log N).
// Auxiliary space: O(1), As no extra space is required.
int findPlatform(int arr[], int dep[], int n){
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    // 	for(int i=0;i<n;i++)
    // 	    cout<<arr[i]<<" ";
    // 	cout<<endl;
    // 	for(int i=0;i<n;i++)
    // 	    cout<<dep[i]<<" ";
        int a=1,d=1;
    	int count=0;
    	int maxCount=0;
    	while(a<n && d<n){
    	    if(arr[a]<=dep[d]){
    	        count++;
    	        a++;
    	    }
    	    else if(arr[a]>dep[d]){
    	        count--;
    	        d++;
    	    }
    	    maxCount=max(maxCount,count);
    	}
    	return maxCount;
}


// Method 4 - Using Multiset
// Time Complexity: O( N* LogN).
// Since we are inserting into multiset and it maintain elements in sorted order. So N insert operations in multiset requires N*LogN time complexity. 
// Space Complexity: O(N).  
// We are using multiset which will have 2*N elements.

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
