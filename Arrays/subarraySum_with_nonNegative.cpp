#define ll long long int 
void subarraySum(int arr[], int n, int s){
    ll curr_sum = arr[0];
    ll start = 0;
    for(ll i=1;i<=n;i++){
        while(curr_sum>s && start<=i-2) {
            curr_sum=curr_sum-arr[start];
            start++;
        }
        if(curr_sum==s){
            cout<<start+1<<" "<<i;
            return;
        }

        if(i<n)
            curr_sum = curr_sum + arr[i];
    }
    cout<<-1;
    return ;
    
}
