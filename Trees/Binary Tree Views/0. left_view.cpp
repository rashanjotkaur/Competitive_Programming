// Left View of Binary Tree
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// Method 2: Using Recursion
void leftViewFun(Node *root, vector <int> &res, int level, int &maxLevel){
    if(root==NULL)
        return ;
        
    if(maxLevel<level){
        maxLevel=level;
        res.push_back(root->data);
    }
    
    leftViewFun(root->left,res,level+1,maxLevel);
    leftViewFun(root->right,res,level+1,maxLevel);
}
vector <int> leftView(Node *root){
    vector <int> res;
    int maxLevel=-1;
    leftViewFun(root,res,0,maxLevel);
    return res;
}


// Method 1: Level Order Traversal
vector <int> leftView(Node *root){
    vector <int> res;
    if(root==NULL)
        return res;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        res.push_back(q.front()->data);
        int size=q.size();
        while(size--){
            Node *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return res;
}
