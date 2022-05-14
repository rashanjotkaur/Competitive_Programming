// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/#
// https://leetcode.com/problems/find-distance-in-a-binary-tree/

// Steps:
// Step 1: Check if the both a & b exist in tree or not
// Step 2: If they exist then find the lca
// Step 3: Then make that lca as a root, and find the distance of a & b from the new root.

// Function - Main
int findDist(Node* root, int a, int b) {
        if(root==NULL)
            return -1;
        
        // Step 1        
        bool aExist=false,bExist=false;
        find(root,a,b,aExist,bExist);
        
        // Step 2
        if(aExist && bExist){
            struct Node* lca=lowestCommonAncestor(root,a,b);

            // Step 3: 
            int edges1=-1,edges2=-1;
            findDistNodeLCA(lca,a,b,0,edges1,0,edges2);
            return edges1+edges2;
        }
        else
            return -1;
}


// Function 1 - find both nodes if they exist or not
// Method 1
void find(Node* root, int a, int b, bool &aExist, bool &bExist){
        if(root==NULL)
            return ;
        if(root->data==a)
            aExist=true;
        if(root->data==b)
            bExist=true;
        
        if(aExist && bExist)
            return ;
            
        find(root->left,a,b,aExist,bExist);
        find(root->right,a,b,aExist,bExist);
}
// Method 2
void find(Node *root, int a, int b, Node* &r1, Node* &r2){
    if(root==NULL)
        return ;
    if(root->data==a)
        r1 = root;
    if(root->data==b)
        r2 = root;
    find(root->left,a,b,r1,r2);
    find(root->right,a,b,r1,r2);
}


// Function 3 - Find Lowest Common Ancestor
Node* lowestCommonAncestor(Node* root,int a,int b){
        if(root==NULL)
            return NULL;
        if(root->data==a || root->data==b)
            return root;
        
        Node* l=lowestCommonAncestor(root->left,a,b);
        Node* r=lowestCommonAncestor(root->right,a,b);
        if(l && r)
            return root;
        return l?l:r;
}


// Function 4 - Finding distance between lowest common ancestor and the given nodes
void findDistNodeLCA(Node* root, int a, int b, int level1, int &maxLevel1, 
        int level2, int &maxLevel2){
        if(root==NULL)
            return ;
        if(root->data==a)
            maxLevel1=level1;
        if(root->data==b)
            maxLevel2=level2;
            
        if(maxLevel1!=-1 && maxLevel2!=-1)
            return ;
            
        findDistNodeLCA(root->left,a,b,level1+1,maxLevel1,level2+1,maxLevel2);
        findDistNodeLCA(root->right,a,b,level1+1,maxLevel1,level2+1,maxLevel2);
}
