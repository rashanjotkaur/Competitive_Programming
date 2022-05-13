// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// Method 1 - Using Queue - Level Order Traversal
vector<int> leftView(Node *root){
    vector <int> res;
    if(root==NULL)
        return res;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        res.push_back(q.front()->data);
        int n=q.size();
        while(n--){
            struct Node* temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return res;
}


// Method 2 - Same as above, we are using NULL as delimiter
// Iterative Method using queue
vector <int> leftView(Node *root){
    vector <int> res;
    if(root==NULL) 
        return res; 
        
    queue <Node*> q;
    q.push(root); 
    q.push(NULL);       // Delimiter
    while(!q.empty()) { 
        res.push_back(q.front()->data);
        while(q.front()!=NULL){
            struct Node* temp=q.front();
            q.pop(); 
            if (temp->left) 
                q.push(temp->left); 
            if (temp->right) 
                q.push(temp->right); 
        } 
        q.pop();
        if(q.empty())
            break;
        q.push(NULL); 
    } 
    return res;
}


// Method 3 - Using Recursion
void leftViewRecursion(Node *root,int level,int &maxLevel,vector <int> &res){
    if(root==NULL)
        return ;
    
    if(maxLevel<level){
        res.push_back(root->data);
        maxLevel=level;
    }
    
    leftViewRecursion(root->left,level+1,maxLevel,res);
    leftViewRecursion(root->right,level+1,maxLevel,res);
}
vector <int> leftView(Node *root){
    vector <int> res;
    if(root==NULL) 
        return res; 
    int maxLevel=0;
    leftViewRecursion(root,1,maxLevel,res);
    return res;
}
