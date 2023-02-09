// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Method 1: Level Order Traversal

// Note: 
// If 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

vector <int> topView(Node *root){
        vector <int> res;
        if(root==NULL)
            return res;
        map <int,int> mp;  
        queue <pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp=q.front().first;
            int hd=q.front().second;
            q.pop();
            
            if(mp.find(hd)==mp.end())
                mp[hd]=temp->data;
            
            if(temp->left)
                q.push({temp->left,hd-1});
            if(temp->right)
                q.push({temp->right,hd+1});
        }
        for(auto x:mp)
            res.push_back(x.second);
        return res;
}



// Method 2: Using Recursion
// Approach:
// 1. Here we use the two variables, one for the HORIZONTAL distance of the current node from the root and another for the DEPTH of the current 
//    node from the root. 
// 2. We use the HORIZONTAL distance for indexing. If one node with the same HORIZONTAL distance comes again, we check if the DEPTH of the new node is 
//    lower or higher with respect to the current node with the same HORIZONTAL distance in the map. 
// 3. If the DEPTH of the new node is lower, then we replace it.

// Func 1: 
vector <int> topView(Node *root){
        vector <int> res;
        if(root==NULL)
            return res;
        map <int,pair<int,int>> mp;
        topViewFun(root,0,0,mp);
        for(auto x:mp)
            res.push_back(x.second.first);
        return res;
}

// Func 2:
void topViewFun(Node *root, int level,int hd, map <int,pair<int,int>> &mp){
        if(root==NULL)
            return ;
        if(mp.find(hd)==mp.end())
            mp[hd]={root->data,level};
        else if(level<mp[hd].second){
            mp[hd].second=level;
            mp[hd].first=root->data;
        }
        topViewFun(root->left,level+1,hd-1,mp);
        topViewFun(root->right,level+1,hd+1,mp);
}
    
