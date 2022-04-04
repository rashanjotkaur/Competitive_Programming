#include <bits/stdc++.h>
using namespace std;
struct Interval{
    int start;
    int end;
};
bool sortbyfirst(Interval a,Interval b){
    if(a.start==b.start)
        return a.end<b.end;
    return a.start<b.start;
}
int main() {
    int n;
    cin>>n;
    Interval arr[n];
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        arr[i].start=x;
        arr[i].end=y;
    }
    sort(arr,arr+n,sortbyfirst);
    for(int i=0;i<n;i++)
        cout<<arr[i].start<<" "<<arr[i].end<<endl;
	return 0;
}
// Input
// 5
// 3 4
// 3 2
// 1 2
// 2 4
// 1 1
