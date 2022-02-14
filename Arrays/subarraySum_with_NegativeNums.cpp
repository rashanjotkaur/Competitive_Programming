#include <bits/stdc++.h>
using namespace std;
void subarraySum(int arr[],int n,int sum){
    int currSum=0,maxLen;
    unordered_map <int,int> ump;
    for(int i=0;i<n;i++){
        currSum=currSum+arr[i];
        if(currSum==sum){
            cout<<"0"<<" "<<i<<endl;
            return ;
        }
        if(ump.find(currSum)==ump.end())
            ump[currSum]=i;
        if(ump.find(currSum-sum)!=ump.end()){
            cout<<ump[currSum-sum]+1<<" "<<i<<endl;
            return ;
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,sum;
	    cin>>n>>sum;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    subarraySum(arr,n,sum);
	}
	return 0;
}
// Input
// 1
// 5 -20
// 10 2 -2 -20 10
