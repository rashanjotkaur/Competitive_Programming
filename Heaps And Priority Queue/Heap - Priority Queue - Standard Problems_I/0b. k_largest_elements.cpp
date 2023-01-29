// K Largest Elements in an Array
// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// Problem Link: https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

vector <int> kLargest(int arr[], int n, int k) {
	    priority_queue <int,vector<int>,greater<int>> pq;
	    for(int i=0;i<n;i++){
	        pq.push(arr[i]);
	        if(pq.size()>k)
	            pq.pop();
	    }
	    vector <int> res;
	    while(!pq.empty()){
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(res.begin(),res.end());
	    return res;
}
