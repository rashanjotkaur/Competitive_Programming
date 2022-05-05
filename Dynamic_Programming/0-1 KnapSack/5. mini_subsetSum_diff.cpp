// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#

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


// 
