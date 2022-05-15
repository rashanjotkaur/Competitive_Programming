// All Elements in Two Binary Search Trees

// Method 1 - Using Extra Space
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> vec;
        if (root1 == NULL && root2 == NULL)
            return vec;
        if (root1 && root2 == NULL)
        {
            inorder(root1, vec);
            return vec;
        }
        if (root1 == NULL && root2)
        {
            inorder(root2, vec);
            return vec;
        }
        if (root1 && root2)
        {
            vector<int> vec1;
            vector<int> vec2;
            inorder(root1, vec1);
            inorder(root2, vec2);
            int n1 = vec1.size();
            int n2 = vec2.size();
            int i = 0, j = 0;
            while (i < n1 && j < n2)
            {
                if (vec1[i] < vec2[j])
                {
                    vec.push_back(vec1[i]);
                    i++;
                }
                else if (vec2[j] < vec1[i])
                {
                    vec.push_back(vec2[j]);
                    j++;
                }
                else if (vec1[i] == vec2[j])
                {
                    vec.push_back(vec1[i]);
                    vec.push_back(vec2[j]);
                    i++;
                    j++;
                }
            }
            while (i < n1)
            {
                vec.push_back(vec1[i]);
                i++;
            }
            while (j < n2)
            {
                vec.push_back(vec2[j]);
                j++;
            }
        }
        return vec;
    }
};

// Method 2 - Best Solution
//            Time Complexity : O(N), maximum n elements are traversed
//            Space Complexity : O(N), size of vector (tree1 + tree2)
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> vec;
    stack<TreeNode *> s1, s2;
    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
        {
            root1 = s1.top();
            s1.pop();
            vec.push_back(root1->val);
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            s2.pop();
            vec.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return vec;
}