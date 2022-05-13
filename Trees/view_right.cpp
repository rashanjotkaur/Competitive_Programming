

//  Method 1 - Using Queue 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> vec;
        if(root==NULL)
            return vec;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                struct TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(n==0)
                    vec.push_back(temp->val);
            }
        }
        return vec;
    }
};


// Method 2 - Using Queue (NULL)
void rightView(Node *root){
    if(root==NULL)  
        return ;
    queue <struct Node*> q;
    q.push(root);
    q.push(NULL);
    struct Node *temp;
    while(q.front()!=NULL){
        while(q.front()!=NULL){
            temp=q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
        cout<<temp->data<<" ";
        q.push(NULL);
        q.pop();
    }
}


// Method 3 - Using Recursion
class Solution {
public:
    void rightSideView(TreeNode *root, int level, int &maxLevel, vector <int> &res){
        if(root==NULL)
            return;
        if(maxLevel<level){
            res.push_back(root->val);
            maxLevel=level;
        }
        rightSideView(root->right,level+1,maxLevel,res);
        rightSideView(root->left,level+1,maxLevel,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> res;
        if(root==NULL)
            return res;
        int maxLevel=0;
        rightSideView(root,1,maxLevel,res);
        return res;
    }
};
