// Count all nodes that are at distance k from a leaf node.
// Problem Link: https://practice.geeksforgeeks.org/problems/node-at-distance/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Func 1:
int printKDistantfromLeaf(Node* root, int k){
	vector <Node*> temp;
    unordered_map <Node*,int> res;
    find(root,k,temp,res);
    return res.size();
}

// Func 2: 
void find(Node *root, int k, vector <Node*> &temp, unordered_map <Node*,int> &res){
    if(root==NULL)
        return ;
    temp.push_back(root);
    if(root->left==NULL && root->right==NULL && temp.size()>k)
        res[temp[temp.size()-1-k]]++;
        
    find(root->left,k,temp,res);
    find(root->right,k,temp,res);
    temp.pop_back();
}

