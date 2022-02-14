int getMaxWidth(Node* root){
    if(root==NULL)
        return 0;
    queue <struct Node*> q;
    int maxi=0;
    q.push(root);
    // q.push(NULL);
    while(!q.empty()){
        int size=q.size();
        maxi=max(maxi,size);
        while(size--){
            struct Node *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return maxi;
}
