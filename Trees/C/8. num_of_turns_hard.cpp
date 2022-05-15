// https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1/#


// Function - Main
int NumberOFTurns(struct Node* root, int first, int second){
        if(root==NULL)
            return -1;
        if(first==second)
            return -1;
            
        struct Node *lca=LCA(root,first,second);
        
        if(lca->data==first){
            int d=dis(lca,second);
            return d==0?-1:d;
        }
        if(lca->data==second){
            int d=dis(lca,first);
            return d==0?-1:d;
        }
            
        int d1=dis(lca,first);
        int d2=dis(lca,second);
        return d1+d2+1;
}


// Function 1
Node* LCA(struct Node* root,int x,int y){
        if(root==NULL)
            return root;
            
        if(root->data==x || root->data==y)
            return root;
        
        Node *l=LCA(root->left,x,y);
        Node *r=LCA(root->right,x,y);
        
        if(l && r)
            return root;
        return l?l:r;
}


// Function 2
int dis(Node *root, int key){
        int maxTurns=0;
        disHelper(root,key,0,maxTurns,false,false);
        return maxTurns;
}


// Function 3
void disHelper(Node* root,int key,int turns,int &maxTurns,bool left,bool right){
        if(root==NULL)
            return ;
         
        if(root->data==key){
            if(turns>maxTurns)
                maxTurns=turns;   
        }
            
        int tempTurns=right?turns+1:turns;
        disHelper(root->left,key,tempTurns,maxTurns,true,false);
        
        tempTurns=left?turns+1:turns;
        disHelper(root->right,key,tempTurns,maxTurns,false,true);
}
