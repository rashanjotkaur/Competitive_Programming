// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#

// For trees to be Isomorphic 
// 1. It should either be mirrors of each other.
// 2. OR Identical to each other.
class Solution{
  public
    bool isIsomorphic(Node *root1,Node *root2){
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        if(root1->data!=root2->data)
            return false;
            
        bool mirror_left=isIsomorphic(root1->left,root2->right);
        bool mirror_right=isIsomorphic(root1->right,root2->left);
        
        bool identical_left=isIsomorphic(root1->left,root2->left);
        bool identical_right=isIsomorphic(root1->right,root2->right);
        return (mirror_left & mirror_right) | (identical_left & identical_right);
    }
};
