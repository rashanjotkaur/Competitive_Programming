// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1/#

// Method 1
long int sumBT(Node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->key;
    int sum=root->key+sumBT(root->left)+sumBT(root->right);
    return sum;
}

// Method 2
void sumOfTree(struct Node *root, long int &sum){
    if(root==NULL)
        return ;
    sumOfTree(root->left,sum);
    sum=sum+root->key;
    sumOfTree(root->right,sum);
}
long int sumBT(Node* root){
    if(root==NULL)
        return 0;
    long int sum=0;
    sumOfTree(root,sum);
    return sum;
}
