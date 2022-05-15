// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Method 1 - Using 2 Stacks
void printSpiral(Node *root){
  if(root==NULL)  
      return ;
	stack <struct Node*> s1;
	stack <struct Node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
	    while(!s1.empty()){
	        struct Node *temp=s1.top();
	        s1.pop();
	        cout<<temp->data<<" ";
	        if(temp->right)
	            s2.push(temp->right);
	        if(temp->left)
	            s2.push(temp->left);
	    }
	    while(!s2.empty()){
	        struct Node *temp=s2.top();
	        s2.pop();
	        cout<<temp->data<<" ";
	        if(temp->left)
	            s1.push(temp->left);
	        if(temp->right)
	            s1.push(temp->right);
	    }
	}
}

// Method 2 - Using Queue Only
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> res;
        if(root==NULL)
            return res;
        queue <TreeNode*> q;
        q.push(root);
        bool revRow=false;
        while(!q.empty()){
            int n=q.size();
            vector <int> vec;
            while(n--){
                struct TreeNode *temp=q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(revRow)
                reverse(vec.begin(),vec.end());
            res.push_back(vec);
            revRow=!revRow;
        }
        return res;
    }
};
