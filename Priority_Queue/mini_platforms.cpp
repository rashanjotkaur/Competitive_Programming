// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/

// Method - Using Priority Queue. 
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
