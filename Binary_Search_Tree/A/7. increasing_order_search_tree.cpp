// Increasing Order Search Tree
// Link: https://leetcode.com/problems/increasing-order-search-tree/

TreeNode *newNode(int x)
{
    TreeNode *temp = new TreeNode;
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insert_right(TreeNode *temp, TreeNode *&root)
{
    if (root == NULL)
    {
        root = temp;
        return;
    }

    TreeNode *temp1 = root;
    while (temp1->right)
    {
        temp1 = temp1->right;
    }
    temp1->right = temp;
    return;
}
void inorder(TreeNode *root, TreeNode *&newroot)
{
    if (root == NULL)
        return;

    inorder(root->left, newroot);

    TreeNode *temp = newNode(root->val);
    // cout<<"temp->val "<<temp->val<<endl;
    insert_right(temp, newroot);

    inorder(root->right, newroot);
}
TreeNode *increasingBST(TreeNode *root)
{
    TreeNode *newroot = NULL;
    inorder(root, newroot);
    return newroot;
}