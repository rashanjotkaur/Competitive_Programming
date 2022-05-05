// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
// https://www.interviewbit.com/problems/minimum-difference-subsets/

// Method 1:
public:
    typedef long long int ll;
	  int minDifference(int arr[], int n)  { 
		ll sum=0;
		for(ll i=0;i<n;i++)
		    sum+=arr[i];
		bool dp[n+1][sum+1];
		for(ll i=0;i<=n;i++)
		    dp[i][0]=true;
		for(ll j=1;j<=sum;j++)
		    dp[0][j]=false;
		for(ll i=1;i<=n;i++){
		    for(ll j=1;j<=sum;j++){
			if(arr[i-1]<=j)
			    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
			    dp[i][j]=dp[i-1][j];
		    }
		}
	       // for(ll j=0;j<=sum;j++)
	       //     cout<<dp[n][j]<<" ";
	       // cout<<endl;
		ll s2=sum/2;
		for(ll j=s2;j>=0;j--){
		    if(dp[n][j]==true)
			return sum-2*j;
		}
	  } 


// Method 2: Instead of making dp till sum, we can make it till s2 only 
// s1+s2=sum
// s1-s2=x
// 2*s2=sum-x
// x=sum-2*s2 // We have to return this -> as this is the minimum difference, when s2 is maximum.
// x>=0
// Hence, sum-2*s2>=0
// s2<=sum/2
public:
    	typedef long long int ll;
	int minDifference(int arr[], int n)  { 
	    ll sum=0;
	    for(ll i=0;i<n;i++)
	        sum+=arr[i];
	    ll s2=sum/2;
	    bool dp[n+1][s2+1];
	    for(ll i=0;i<=n;i++)
	        dp[i][0]=true;
	    for(ll j=1;j<=s2;j++)
	        dp[0][j]=false;
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=s2;j++){
	            if(arr[i-1]<=j)
	                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	    for(ll j=s2;j>=0;j--){
	        if(dp[n][j]==true)
	            return sum-2*j;
	    }
	} 
