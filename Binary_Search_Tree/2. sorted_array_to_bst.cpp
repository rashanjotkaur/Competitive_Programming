TreeNode *insert(vector<int> nums, int l, int r)
{
    int mid = (l + r) / 2;
    if (l <= r)
    {
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = insert(nums, l, mid - 1);
        root->right = insert(nums, mid + 1, r);
        return root;
    }
    return NULL;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return insert(nums, 0, n - 1);
}