// Validate Binary Search Tree

void inorder(TreeNode *root, TreeNode *&prev, bool &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, prev, ans);
    if (prev)
    {
        if (prev->val >= root->val)
        {
            ans = false;
            return;
        }
    }
    prev = root;
    inorder(root->right, prev, ans);
}
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    TreeNode *prev = NULL;
    bool ans = true;
    inorder(root, prev, ans);
    return ans;
}