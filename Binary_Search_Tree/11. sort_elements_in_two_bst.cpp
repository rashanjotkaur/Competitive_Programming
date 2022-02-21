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