// Method 1-Store inorder traversal of both trees and then use sorting
void inorder(struct Node *root,vector <int> &v){
    if(root==NULL)
        return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
vector<int> merge(Node *root1, Node *root2){
    vector <int> v;
    if(root1==NULL && root2==NULL)
        return v;

    vector <int> v1;
    inorder(root1,v1);
    
    vector <int> v2;
    inorder(root2,v2);
    
    if(root1 && root2==NULL)
        return v1;
    if(root1==NULL && root2)
        return v2;

    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }
    return v;
}

// Method 2- using inorder with Stack
// Time Complexity-O(n+m)
// Space Complexity-O(height of T1 + height of T2)
void insertNodes(Node *root, stack<Node*> &s){
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
}
vector<int> merge(Node *root1, Node *root2){
    vector <int> v;
    stack <Node*> s1;
    stack <Node*> s2;
 
    insertNodes(root1,s1);
    insertNodes(root2,s2);
   
    while(!s1.empty() || !s2.empty()){
        int a=(!s1.empty() ? s1.top()->data:INT_MAX);
        int b=(!s2.empty() ? s2.top()->data:INT_MAX);
       
       if(a<=b){
           v.push_back(a);
           Node *temp=s1.top();
           s1.pop();
           insertNodes(temp->right,s1);
       }
       else{
           v.push_back(b);
           Node *temp=s2.top();
           s2.pop();
           insertNodes(temp->right,s2);
           
       }
   }
   return v;
}
