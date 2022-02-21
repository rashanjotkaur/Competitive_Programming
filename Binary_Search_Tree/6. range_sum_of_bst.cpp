// Find the sum of values of all nodes with a value in the inclusive range [low, high].
// Link: https://leetcode.com/problems/range-sum-of-bst/

void inorder(TreeNode *root, int low, int high, int &sum)
{
    if (root == NULL)
        return;
    inorder(root->left, low, high, sum);

    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
        cout << root->val << endl;
    }

    inorder(root->right, low, high, sum);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    inorder(root, low, high, sum);
    return sum;
}