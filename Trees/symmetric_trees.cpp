// https://leetcode.com/problems/symmetric-tree/\

// Method 1
class Solution {
public:
    bool areMirror(struct TreeNode *a, struct TreeNode *b){
        if(a==NULL && b==NULL)
            return true;
        if(a==NULL || b==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        int l=areMirror(a->left,b->right);
        int r=areMirror(a->right,b->left);
        return l & r;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return false;
        struct TreeNode *tree1, *tree2;
        tree1=root->left;
        tree2=root->right;
        return areMirror(tree1,tree2);
    }
};

// Method 2
bool isIdentical(struct Node *r1,struct Node *r2){
    if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    if(r1->data!=r2->data)
        return false;
    bool l=isIdentical(r1->left,r2->left);
    bool r=isIdentical(r1->right,r2->right);
    return l & r;
}
void mirror(struct Node **root){
    if(*root==NULL) return ;
    swap((*root)->left,(*root)->right);
    mirror(&((*root)->left));
    mirror(&((*root)->right));
}
int areMirror(Node* a, Node* b) {
    mirror(&a);
    return isIdentical(a,b);
}
