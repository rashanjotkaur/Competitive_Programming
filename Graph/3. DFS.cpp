// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

// Method 1 - Use Stack 
vector <int> dfsOfGraph(int v, vector<int> adj[]) {
        vector <int> res;
        stack <int> s;
        vector <bool> vis(v,false);
        s.push(0);
        vis[0]=true;
        while(!s.empty()){
            int i=s.top();
            s.pop();
            res.push_back(i);
            for(auto j:adj[i]){
                if(!vis[j]){
                    vis[j]=true;
                    s.push(j);
                }
            }
        }
        return res;
}


// Method 2 - Recursive Approach
// Function - Main
vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector <bool> vis(v,false);
        vector <int> res;
        dfs(0,adj,v,vis,res);
        return res;
}
// Function - 1
void dfs(int i,vector <int> adj[],int v,vector <bool> &vis,vector <int> &res){
        vis[i]=true;
        res.push_back(i);
        for(auto j:adj[i]){
            if(!vis[j])
                dfs(j,adj,v,vis,res);
        }
}
    
