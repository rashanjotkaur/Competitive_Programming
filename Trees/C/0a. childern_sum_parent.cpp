// https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

int isSumProperty(Node *root){
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return 1;
        int ls=root->left?root->left->data:0;
        int rs=root->right?root->right->data:0;
        return ((root->data==ls+rs) && isSumProperty(root->left) && isSumProperty(root->right));
}


