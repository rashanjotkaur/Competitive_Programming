// Method 1-using recursive inorder traversals
void traverse(struct Node *root,unordered_map <int,bool> &ump){
    if(root==NULL)
        return ;
    ump[root->data]=true;
    traverse(root->left,ump);
    traverse(root->right,ump);
}
void inorder(struct Node *root,vector <int> &vec,unordered_map <int,bool> ump){
    if(root==NULL)
        return ;
    inorder(root->left,vec,ump);
    if(ump[root->data]==true)
        vec.push_back(root->data);
    inorder(root->right,vec,ump);
}
vector <int> printCommon(Node *r1, Node *r2){
    unordered_map <int,bool> ump;
    vector <int> vec;
    if(r1==NULL || r2==NULL)
        return vec;
    traverse(r1,ump);
    inorder(r2,vec,ump); 
    return vec;
}

// Method 2-iterative inorder traversal
vector <int> printCommon(Node *root1, Node *root2){
    stack <Node*> s1,s2;
    Node *curr1=root1, *curr2=root2;
    vector <int> vec;
    while((curr1!=NULL || !s1.empty()) && (curr2!=NULL || !s2.empty())){
        while(curr1){
            s1.push(curr1);
            curr1 = curr1->left;
        }
        while(curr2) {
            s2.push(curr2);
            curr2 = curr2->left;
        }
        if(!s1.empty() && !s2.empty()){
            curr1 = s1.top(); 
            curr2 = s2.top();
            if(curr1->data == curr2->data) {
                vec.push_back(curr1->data);
                s1.pop(); 
                s2.pop();
                curr1 = curr1->right;
                curr2 = curr2->right;
            } 
            else if(curr1->data > curr2->data) {
                curr2 = curr2->right;
                s2.pop();
                curr1 = NULL;
            }
            else{
                curr1 = curr1->right;
                s1.pop();
                curr2 = NULL;
            }
        }
    }
    return vec;
}



