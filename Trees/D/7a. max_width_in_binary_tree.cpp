// https://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/
// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int getMaxWidth(Node* root){
    if(root==NULL)
        return 0;
    queue <struct Node*> q;
    int maxi=0;
    q.push(root);
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
