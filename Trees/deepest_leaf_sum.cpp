// https://leetcode.com/problems/deepest-leaves-sum/

// Method 1-Using ordered map with vertical depth variable
class Solution {
public:
    void deepestLeaves(TreeNode *root,int vd,map <int,vector<int>> &mp){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL){
            mp[vd].push_back(root->val);
            return ;
        }
        deepestLeaves(root->left,vd+1,mp);
        deepestLeaves(root->right,vd+1,mp);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int vd=0;
        map <int,vector<int>> mp;
        deepestLeaves(root,vd,mp);
        
        int sum=0;
        // To access last element of map
        auto it=mp.end();
        it--;
        // cout<<"level: "<<it->first<<endl;
        vector <int> temp=it->second;
        for(int i=0;i<temp.size();i++)
            sum=sum+temp[i];
        return sum;
    }
};


// Method 2-Using Level Order Traversal
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                struct TreeNode* temp=q.front();
                q.pop();
                sum=sum+temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);   
            }
            if(q.empty())
                return sum;
            sum=0;
        }
        return sum;
    }
};
