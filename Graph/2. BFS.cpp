// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/#

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector <int> res;
        queue <int> q;
        vector <bool> vis(v,false);
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            res.push_back(i);
            for(auto j:adj[i]){
                if(!vis[j]){
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
        return res;
}
