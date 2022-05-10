// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
// Note: By default, C++ creates a max-heap for priority queue.


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    //By default, elements are in non-increasing order
    priority_queue <int> pq;
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
