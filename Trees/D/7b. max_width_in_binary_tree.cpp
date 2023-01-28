// Maximum Width of Binary Tree
// Video Link: https://www.youtube.com/watch?v=ZbybYvcVLks
// Striver Solution: https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/
// Explaination: https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/1802311/c-bfs-easy-to-understand-full-explanation/
// Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

// Method 2: To overcome the overflow -> reduce the minimum value of index
int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxWidth=0;
        queue <pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int start=q.front().second;
            int end=q.back().second;
            maxWidth=max(maxWidth,end-start+1);
            int size=q.size();
            while(size--){
                TreeNode *temp=q.front().first;
                int i=q.front().second-start; //As "start" will be the minimum index.
                q.pop();
                if(temp->left)
                    q.push({temp->left,(long long)2*i+1});
                if(temp->right)
                    q.push({temp->right,(long long)2*i+2});
            }
        }
        return maxWidth;
}


// Method 1: Using long long
int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        long long maxWidth=0;
        queue <pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            long long start=q.front().second;
            long long end=q.back().second;
            maxWidth=max(maxWidth,end-start+1);
            long long size=q.size();
            while(size--){
                TreeNode *temp=q.front().first;
                long long i=q.front().second;
                q.pop();
                if(temp->left)
                    q.push({temp->left,(long long)2*i+1});
                if(temp->right)
                    q.push({temp->right,(long long)2*i+2});
            }
        }
        return maxWidth;
}

