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

// Method 2-Without using extra space
class Solution
{
public:
    TreeNode *n1 = NULL, *n2 = NULL;
    void reverse_inorder(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL || n2)
            return;

        reverse_inorder(root->right, prev);
        if (prev)
        {
            if (root->val > prev->val)
            {
                // cout<<prev->val<<" "<<root->val<<endl;
                n2 = prev;
                return;
            }
        }
        prev = root;
        reverse_inorder(root->left, prev);
    }
    void inorder(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL || n1)
            return;

        inorder(root->left, prev);
        if (prev)
        {
            if (prev->val > root->val)
            {
                // cout<<prev->val<<" "<<root->val<<endl;
                n1 = prev;
                return;
            }
        }
        prev = root;
        inorder(root->right, prev);
    }
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        TreeNode *reverse_root = root;

        TreeNode *prev1 = NULL;
        inorder(root, prev1);

        TreeNode *prev2 = NULL;
        reverse_inorder(reverse_root, prev2);

        // cout<<n1->val<<" "<<n2->val<<endl;
        swap(n1->val, n2->val);
