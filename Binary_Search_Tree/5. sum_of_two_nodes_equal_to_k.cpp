// If Sum of two nodes in BST is equal to k, return true else false
// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1: Using extra space
void inorder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> vec;
    inorder(root, vec);
    int l = 0, r = vec.size() - 1;
    while (l < r)
    {
        if (vec[l] + vec[r] > k)
            r--;
        else if (vec[l] + vec[r] < k)
            l++;
        else if (vec[l] + vec[r] == k)
            return true;
    }
    return false;
}

// Method-2: Using set
bool inorder(TreeNode *root, unordered_set<int> &set, int k)
{
    if (root == NULL)
        return false;

    bool l, r;
    l = inorder(root->left, set, k);

    if (set.find(k - root->val) != set.end())
        return true;
    else
        set.insert(root->val);

    r = inorder(root->right, set, k);
    return l || r;
}
bool findTarget(TreeNode *root, int k)
{
    unordered_set<int> set;
    return inorder(root, set, k);
}