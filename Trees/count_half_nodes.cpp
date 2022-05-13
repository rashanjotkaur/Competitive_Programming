// https://www.geeksforgeeks.org/count-half-nodes-in-a-binary-tree-iterative-and-recursive/

// Method 1
int countHalfNodes(struct Node *root){
    if(root==NULL)
        return 0;
    
    int count=0;
    if((root->left==NULL && root->right) || (root->left && root->right==NULL))
        count++;
    
    count=count+countHalfNodes(root->left)+countHalfNodes(root->right);
    return count;
}

// Method 2: Preorder Traversal
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

void countHalfNodes(struct Node *root,int &count){
    if(root==NULL)
        return ;
    if((root->left && root->right==NULL) || (root->left==NULL && root->right))
        count++;
    countHalfNodes(root->left,count);
    countHalfNodes(root->right,count);
}

struct Node* newNode(int data){
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){
	/* 2
	  / \
	 7	 5
	 \	 \
	 6	  9
	/ \  /
   1  11 4
  */

	struct Node *root=newNode(2);
	root->left=newNode(7);
	root->right=newNode(5);
	root->left->right=newNode(6);
	root->left->right->left=newNode(1);
	root->left->right->right=newNode(11);
	root->right->right=newNode(9);
	root->right->right->left=newNode(4);

    int count=0;
	countHalfNodes(root,count);
    cout<<count<<endl;
    
	return 0;
}
