// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Method 1
class Solution {
public:
    int stringToNum(string s){
        int num=0;
        int n=s.size();
        for(int i=0;i<n;i++)
            num=num*10+(s[i]-'0');
        // cout<<num<<endl;
        return num;
    }
    void rootToLeaf(TreeNode *root, string str, vector <string> &vec){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            str=str+to_string(root->val);
            vec.push_back(str);
            return ;
        }
        rootToLeaf(root->left,str+to_string(root->val),vec);
        rootToLeaf(root->right,str+to_string(root->val),vec);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        string str="";
        vector <string> vec;
        rootToLeaf(root,str,vec);
        
        int sum=0;
        for(int i=0;i<vec.size();i++)
            sum+=stringToNum(vec[i]);
        return sum;
    }
};


// Method 2-Without using any extra space(or converting into string)
class Solution {
public:
    void rootToLeaf(TreeNode *root, int num, int &sum){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            num=num*10+root->val;
            cout<<num<<endl;
            sum=sum+num;
            return ;
        }
        rootToLeaf(root->left,num*10+root->val,sum);
        rootToLeaf(root->right,num*10+root->val,sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int num=0,sum=0;
        rootToLeaf(root,num,sum);
        return sum;
    }
};
