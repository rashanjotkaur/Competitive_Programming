#define ll long int 
int maxHappiness (int a[], int b[], int n, int rup){
    priority_queue <pair<int,int>> pq;
    for(ll i=0;i<n;i++)
        pq.push(make_pair(a[i],b[i]));
    ll sum=0;
    for(ll j=0;j<rup;j++){
        int x=pq.top().first;
        int y=pq.top().second;
        sum=sum+x;
        pq.pop();
        int ans=x-y;
        if(ans<0)
            pq.push(make_pair(0,y));
        else{
            pq.push(make_pair(ans,y));
        }
        
    }
    return sum;
}
