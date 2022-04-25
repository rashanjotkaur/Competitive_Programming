// https://practice.geeksforgeeks.org/problems/minimum-swaps/1/

// Method 1 - Using vector of pairs
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
