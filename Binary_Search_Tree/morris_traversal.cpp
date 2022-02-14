void MorrisTraversal(struct Node* root){ 
    struct Node *curr;
    if (root == NULL) 
        return; 
  
    curr = root; 
    while(curr!=NULL){
        if (curr->left==NULL) { 
            cout<<curr->data<<" "; 
            curr = curr->right; 
        } 
        else { 
            /* Find the inorder predecessor of current */
            struct Node *pre = curr->left; 
            while (pre->right != NULL && pre->right != curr) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder predecessor */
            if(pre->right == NULL){ 
                pre->right = curr; 
                curr = curr->left; 
            } 
  
            /* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor */
            else{ 
                pre->right = NULL; 
                cout<<curr->data<<endl; 
                curr = curr->right; 
            } 
        } 
    } 
} 
