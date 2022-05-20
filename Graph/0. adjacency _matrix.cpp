// https://www.geeksforgeeks.org/graph-and-its-representations/

#include <bits/stdc++.h>
using namespace std;

void printGraph(vector <vector<int>> adj, int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
	int v,e;
	cin>>v>>e;
	vector <vector<int>> adj(v,vector<int>(v,0)); 
	int v1,v2;
	for(int i=0;i<e;i++){
	    cin>>v1>>v2;
	    adj[v1][v2]=1;
	    adj[v2][v1]=1;
	}
	printGraph(adj,v);
	return 0;
}
