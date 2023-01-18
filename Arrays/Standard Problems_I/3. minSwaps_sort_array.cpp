// https://practice.geeksforgeeks.org/problems/minimum-swaps/1/
// Method 1 - https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/


// Method 1 - Preferred
// Time Complexity: O(N*logN)
// Space Complexity: O(N)
// Approach: Solve using graph
// 1. The graph will now contain many non-intersecting cycles. 
// 2. Now a cycle with 2 nodes will only require 1 swap to reach the correct ordering, similarly, a cycle with 3 nodes will only require 2 swaps to do so. 
// 3. Hence, ans = Σi=1 to k(cycle_size – 1), where k is the number of cycles

// Using Vector of Pairs
int minSwaps(vector <int> &nums){
	    int n=nums.size();
	    vector <pair<int,int>> vp;
	    for(int i=0;i<n;i++)
	        vp.push_back({nums[i],i});
	    sort(vp.begin(),vp.end());
	    vector <bool> vis(n,false);
	    int swaps=0;
	    for(int i=0;i<n;i++){
	        if(vis[i] || i==vp[i].second)
	            continue;
	        int cycle_size=0;
	        int j=i;
	        while(!vis[j]){
	            vis[j]=true;
	            j=vp[j].second;
	            cycle_size++;
	        }
	        if(cycle_size>0)
	            swaps+=cycle_size-1;
	    }
	    return swaps;
}

//  OR 

// Using Array of Pairs
int minSwaps(vector <int> &nums){
	    int n=nums.size();
	    pair <int,int> ap[n]; //array of pairs
	    for(int i=0;i<n;i++){
	        ap[i].first=nums[i];
	        ap[i].second=i;
	    }
	    sort(ap,ap+n);
	    vector <bool> vis(n,false);
	    int swaps=0;
	    for(int i=0;i<n;i++){
	        if(vis[i] || i==ap[i].second)
	            continue;
	        int cycle_size=0;
	        int j=i;
	        while(!vis[j]){
	            vis[j]=true;
	            j=ap[j].second;
	            cycle_size++;
	        }
	        if(cycle_size>0)
	            swaps+=cycle_size-1;
	    }
	    return swaps;
}


// Method 2 - Using vector of pairs
// Time Complexity: O(N^2)
// Space Complexity: O(N)
int minSwaps(vector <int> &nums){
	    int n=nums.size();
	    vector <pair<int,int>> vec;
	    for(int i=0;i<n;i++)
	        vec.push_back(make_pair(nums[i],i));
	    sort(vec.begin(),vec.end());
	    int swaps=0;
	    for(int i=0;i<n;i++){
	        if(i==vec[i].second)
	            continue;
	        else{
	            int idx=vec[i].second;
	            swap(vec[i].first,vec[idx].first);
	            swap(vec[i].second,vec[idx].second);
	        }
	        if(i!=vec[i].second)
	            i--;
	        swaps++;
	    }
	    return swaps;
}
