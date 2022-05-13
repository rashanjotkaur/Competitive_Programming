// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

class Solution {
public:
    int binaryToDecimal(string s){
        int n=s.size();
        int dec=0;
        for(int i=0;i<n;i++)
            dec=dec+(s[i]-'0')*pow(2,n-1-i);
        return dec;
    }
    void rootToLeaf(TreeNode *root, string str, vector <string> &vec){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            str=str+to_string(root->val);
            // cout<<str<<endl;
            vec.push_back(str);
            return ;
        }
        rootToLeaf(root->left,str+to_string(root->val),vec);
        rootToLeaf(root->right,str+to_string(root->val),vec);
    }
    int sumRootToLeaf(TreeNode *root) {
        if(root==NULL)
            return 0;
        
        vector <string> vec;
        string str="";
        rootToLeaf(root,str,vec);
        
        int sum=0;
        for(int i=0;i<vec.size();i++)
            sum+=binaryToDecimal(vec[i]); 
        return sum;
    }
};
