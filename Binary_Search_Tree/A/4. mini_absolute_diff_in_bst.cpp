// Minimum Absolute Difference in BST
// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// Method 1 - Time Complexity O(n)
//            Space Complexity O(n)
void inorder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}
int getMinimumDifference(TreeNode *root)
{
    vector<int> vec;
    inorder(root, vec);
    int mini = INT_MAX;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int diff = abs(vec[i] - vec[i + 1]);
        mini = min(diff, mini);
    }
    return mini;
}



// Method 2 - Time Complexity O(n)
//            No Space Complexity
void inorder(TreeNode *root, TreeNode *&prev, int &mini)
{
    if (root == NULL)
        return;

    inorder(root->left, prev, mini);

    if (prev)
    {
        int diff = abs(prev->val - root->val);
        mini = min(mini, diff);
        // cout<<prev->val<<" "<<root->val<<endl;
    }
    prev = root;

    inorder(root->right, prev, mini);
}
int getMinimumDifference(TreeNode *root)
{
    int mini = INT_MAX;
    TreeNode *prev = NULL;
    inorder(root, prev, mini);
    return mini;
}