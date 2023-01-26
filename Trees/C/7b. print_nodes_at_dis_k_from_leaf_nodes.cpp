// Nodes at given distance in binary tree
// https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

// Func 1: 
int printKDistantfromLeaf(Node* root, int k){
	  vector <Node*> temp;
    set <Node*> res;    // Using set, as to remove nodes that may get inserted more than once.
    find(root,k,temp,res);
    for(auto x:res)
        cout<<x->data<<" ";
    return res.size();
}

// Func 2
void find(Node *root, int k, vector <Node*> &temp, set <Node*> &res){
    if(root==NULL)
        return ;
    temp.push_back(root);
    if(root->left==NULL && root->right==NULL && temp.size()>k)
        res.insert(temp[temp.size()-1-k]);
        
    find(root->left,k,temp,res);
    find(root->right,k,temp,res);
    temp.pop_back();
}

