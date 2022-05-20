// https://www.geeksforgeeks.org/graph-and-its-representations/
// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1/#

#include <bits/stdc++.h>
using namespace std;

void printGraph(vector <int> adj[], int v){
	for (int i = 0; i < v; i++) {
	    cout<<i;
		for (auto x : adj[i])
			cout<<"->"<<x;
		cout<<endl;
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	vector <int> adj[v]; //for safe side we can keep v+1 
	int v1,v2;
	for(int i=0;i<e;i++){
	    cin>>v1>>v2;
	    adj[v1].push_back(v2);    // undirected
	    adj[v2].push_back(v1);
	}
	printGraph(adj,v);
	return 0;
}
