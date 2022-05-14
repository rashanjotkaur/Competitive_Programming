// https://leetcode.com/problems/binary-tree-coloring-game/ 

// Youtube Video:
// https://www.youtube.com/watch?v=_oFVfRvyplc

This is a game theory question so instead of just making moves, 'blue' need to damage 'red'.
The idea is that every node can have at max 3 neighbour nodes:
1 -> parent, 
2 -> left child, 
3 -> right child, 
and 'red' node will also have at max 3 neighbours. All these 3 neighbours will further have 3 subtrees, 
for 'blue' to win we need to mark one of these neighbours as blue so that one probable path for 'red' to paint red will be blocked.

Steps:
1 -> First, we have to find red node
2 -> Find left and right childern of red node.
3 -> Count nodes under left childern --> red[0]
4 -> Count nodes under right childern --> red[1]
5 -> Count nodes under the red node's parent node --> red[2]= Total Nodes - red[0] - red[1]
6 -> Sort red vector
7 -> Maximum = red[2];
8 -> If Maximum > red[1]+red[0]+1, then will mark these maximum as blue and we will win :) yayyy............
  
// Method 1 - Traversing only for 1 time
// Time Complexity - Under O(n)
class Solution {
public:
    int countNodes(TreeNode* root, int x, vector <int> &red){
        if(root==NULL)
            return 0;
        
        int l=countNodes(root->left,x,red);
        int r=countNodes(root->right,x,red);
        if(root->val==x){
            red[0]=l;
            red[1]=r;
        }
        return l+r+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root==NULL)
            return false;
        
        vector <int> red(3);
        countNodes(root,x,red);
        red[2]=n-red[0]-red[1]-1;  //for parent of aqnother player
        
        sort(red.begin(),red.end());
        if(red[2]>red[1]+red[0]+1)
            return true;
        return false;
    }
};


// Method 2 - Traversing 2 times
// Ist Time - For finding the left and right childern
// 2nd Time - For counting the number of nodes for left and right childern subtree.
//  Time Complexity - More than O(n)
class Solution {
public:
    void findChildern(TreeNode* root, int x, TreeNode* &left, TreeNode* &right){
        if(root==NULL)
            return ;
        
        if(root->val==x){
            left=root->left;
            right=root->right;
        }
        findChildern(root->left,x,left,right);
        findChildern(root->right,x,left,right);
    }
    int countNodes(struct TreeNode* root){
        if(root==NULL)
            return 0;
        int count=1+countNodes(root->left)+countNodes(root->right);
        return count;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root==NULL)
            return false;
        
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        findChildern(root,x,left,right);
        
        vector <int> red(3);
        if(left)
            red[0]=countNodes(left);
        if(right)
            red[1]=countNodes(right);
        red[2]=n-red[0]-red[1]-1;  //for parent
        
        cout<<"redLeft: "<<red[0]<<endl;
        cout<<"redRight: "<<red[1]<<endl;  
        cout<<"redPar: "<<red[2]<<endl; 
        
        sort(red.begin(),red.end());
        if(red[2]>red[1]+red[0]+1)
            return true;
        return false;
    }
};
