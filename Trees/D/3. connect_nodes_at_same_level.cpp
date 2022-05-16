// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Method 1
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *temp=NULL;
            int n=q.size();
            while(n--){
                if(temp)
                    temp->next=q.front();
                temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            temp->next=NULL;
        }
        return root;
    }
};


// Method 2 - Faster than Previous
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue <Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            if(temp){
                temp->next=q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else if(temp==NULL && !q.empty()){
                q.push(NULL);
            }
        }
        return root;
    }
};