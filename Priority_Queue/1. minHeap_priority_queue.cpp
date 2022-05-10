// Syntax: priority_queue <int, vector<int>, greater<int>> pq
// Sorts in increasing order.
// At top, we have minimum element.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    //By default, elements are in increasing order
    priority_queue <int, vector <int>, greater <int> > pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
