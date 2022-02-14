#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll binary_search(ll arr[],ll l,ll r,ll key){
    int mid=(l+r)/2;
    if(l<=r){
        if(arr[mid]==key)
            return mid;
        if(arr[mid]<key)
            return binary_search(arr,mid+1,r,key);
        if(arr[mid]>key)
            return binary_search(arr,l,mid-1,key);
    }
    return -1;
}
ll findMin(ll arr[],ll low,ll high){
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==arr[high])
            high--;
        else if(arr[mid]>arr[high])
            low=mid+1;
        else if(arr[mid]<arr[high])
            high=mid;
    }
    return high;
}
ll findEle(ll arr[],ll n,ll pivot,ll x){
    if(pivot==0)
        return binary_search(arr,0,n-1,x);
    if(arr[pivot]==x)
        return pivot;
    if(x>=arr[0])
        return binary_search(arr,0,pivot-1,x);
    else 
        return binary_search(arr,pivot,n-1,x);
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	    ll x;
	    cin>>x;
	    int pivot=findMin(arr,0,n-1);
	    cout<<findEle(arr,n,pivot,x)<<endl;
	}
	return 0;
}
