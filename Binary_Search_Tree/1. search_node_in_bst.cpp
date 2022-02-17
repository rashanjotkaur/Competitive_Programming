struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    // 1. Start from here if root->val==val
    if (root->val == val)
        return root;

    // 2. Either we go to left subtree or to right subtree by comparing the key with root value
    // If we go to left subtree, then return whatever we get from left subtree, either Key or NULL.
    if (root->val > val)
        return searchBST(root->left, val);

    // 3. If we go to right subtree, then return whatever we get from right subtree, either Key or NULL.
    else
        return searchBST(root->right, val);
}
