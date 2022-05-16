// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#

// Method 1 - Using Unordered Map and Recursion
// Function - Main
void findParent(Node *root, unordered_map <int,int> &ump){
    if(root==NULL)
        return ;
    if(root->left)
        ump[root->left->data]=root->data;
    if(root->right)
        ump[root->right->data]=root->data;
    findParent(root->left,ump);
    findParent(root->right,ump);
}
// Function 1
int kthAncestor(Node *root, int k, int node){
    unordered_map <int,int> par;
    par[root->data]=-1;
    findParent(root,par);
    // for(auto x:par)
    //     cout<<x.first<<" "<<x.second<<endl;
    int anc;
    while(k--){
        anc=par[node];
        node=anc;
        if(anc==-1)
            return anc;
    }
    return anc;
}



// Method 2 - Using Unordered_map and Level Order Traversal
int kthAncestor(Node *root, int k, int node){
    if(root==NULL)
        return 0;
    unordered_map <int,int> par;
    par[root->data]=-1;
    
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            struct Node* temp=q.front();
            q.pop();
            
            if(temp->left){
                par[temp->left->data]=temp->data;
                q.push(temp->left);
            }
            if(temp->right){
                par[temp->right->data]=temp->data;
                q.push(temp->right);
            }
        }
    }
    
    // for(auto x:par)
    //     cout<<x.first<<" "<<x.second<<endl;
        
    int anc;
    while(k--){
        anc=par[node];
        node=anc;
        if(anc==-1)
            return anc;
    }
    return anc;
}

// Method 3 - Backtracking and Storing in Vector - Easy & Important
// Function - Main
int kthAncestor(Node *root, int k, int x){
    vector <int> vec;
    int ans=-1;
    kth(root,x,k,vec,ans);
    return ans;
}
// Function - 1
void kth(struct Node *root,int x,int k,vector <int> &vec,int &ans){
    if(root==NULL)
        return ;

    vec.push_back(root->data);

    if(root->data==x && vec.size()>k){
        int n=vec.size();
        ans=vec[n-1-k];
        return ;
    }

    kth(root->left,x,k,vec,ans);
    kth(root->right,x,k,vec,ans);
    vec.pop_back();
}


// Method 4 - Using Backtracking - Difficult
bool kth(struct Node *root,int x,vector <int> &vec){
     if (root==NULL) 
        return false; 
        
     vec.push_back(root->data);
     if(root->data==x)
        return true;
        
     if(kth(root->left,x,vec) || kth(root->right,x,vec))
        return true;
  
     vec.pop_back();
     return false;
}
int kthAncestor(Node *root, int k, int node){
    vector <int> vec;
    kth(root,node,vec);
    if(k>vec.size()-1 || k<=0)
        return -1;
    int idx=vec.size()-1-k;
    return vec[idx];
}
