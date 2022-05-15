// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    void pathsFun(TreeNode* root,string str,vector <string> &res){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            str=str+to_string(root->val);
            res.push_back(str);
        }
        str=str+to_string(root->val)+"->";
        pathsFun(root->left,str,res);
        pathsFun(root->right,str,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if(root==NULL)
            return res;
        string str="";
        pathsFun(root,str,res);
        return res;
    }
};
