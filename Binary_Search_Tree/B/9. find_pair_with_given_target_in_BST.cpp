// Method 1-Using O(n) auxillary space
void inorder(struct Node *root,vector <int> &v){
    if(root==NULL)
        return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
bool isPairPresent(struct Node *root, int sum){
    if(root==NULL)
        return false;
    vector <int> v;
    inorder(root,v);
    
    int i=0,j=v.size()-1;
    while(i<j){
        int x=v[i]+v[j];
        if(x==sum)
            return true;
        if(x<sum)
            i++;
        else
            j--;
    }
    return false;
}

// Method 2-using inorder stack traversal
bool isPairPresent(struct Node *root, int target){
    stack <Node*> s1;
    stack <Node*> s2;
    bool done1 = false; 
    bool done2 = false; 
    int val1 = 0;
    int val2 = 0; 
    Node *curr1 = root;
    Node *curr2 = root; 
    while (1) {
        // inorder traversal 
        while (done1 == false) { 
            if(curr1){ 
                s1.push(curr1); 
                curr1 = curr1->left; 
            } 
            else { 
                if(!s1.empty()){ 
                    curr1 = s1.top(); 
                    s1.pop();
                    val1 = curr1->data; 
                    curr1 = curr1->right; 
                } 
                done1 = true;
            } 
        } 
        // reverse inorder traversal 
        while(done2 == false){ 
            if(curr2){ 
                s2.push(curr2); 
                curr2 = curr2->right; 
            } 
            else { 
                if(!s2.empty()){ 
                    curr2 = s2.top(); 
                    s2.pop();
                    val2 = curr2->data; 
                    curr2 = curr2->left; 
                } 
                done2 = true; 
            } 
        } 
  
        if ((val1 != val2) && (val1 + val2) == target)
            return true; 
        else if ((val1 + val2) < target) 
            done1 = false; 
        else if ((val1 + val2) > target) 
            done2 = false; 
        if(val1 >= val2) 
            return false; 
    } 
}
