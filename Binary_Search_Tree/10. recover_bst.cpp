// Recover Binary Search Tree


// Method 1-Usig Extra Space
void inorder_insert(TreeNode *root, int &k, vector<int> vec)
{
    if (root == NULL)
        return;

    inorder_insert(root->left, k, vec);
    if (root->val != vec[k])
    {
        root->val = vec[k];
    }
    k++;
    inorder_insert(root->right, k, vec);
}
void inorder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
        return;

    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}
void recoverTree(TreeNode *root)
{
    if (root == NULL)
        return;
    vector<int> vec;
    inorder(root, vec);
    sort(vec.begin(), vec.end());

    int k = 0;
    inorder_insert(root, k, vec);
}


