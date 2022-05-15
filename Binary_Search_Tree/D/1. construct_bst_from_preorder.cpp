// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Method 1 - O(n^2) Complexity - Easy
// Function - Main
TreeNode *bstFromPreorder(vector<int> &pre){
	int n = pre.size();
	TreeNode *root = NULL;
	for (int i = 0; i < n; i++)
		root = createBST(root, pre[i]);
	return root;
}
// Function - 1
TreeNode *createBST(TreeNode *root, int key){
	if (root == NULL){
		root = newNode(key);
		return root;
	}

	if (key < root->val)
		root->left = createBST(root->left, key);
	else
		root->right = createBST(root->right, key);

	return root;
}
// Function - 2
TreeNode *newNode(int key){
	TreeNode *temp = new TreeNode();
	temp->val = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}



// Method 2 - O(n) Complexity - Medium
// Code 1:
// Function - Main
TreeNode* bstFromPreorder(vector <int> &pre) {
    int n=pre.size();
    int preIdx=0;
    return createBST(pre,preIdx,pre[0],INT_MIN,INT_MAX,n);
}
// Function - 1
TreeNode *createBST(vector<int> pre, int &preIdx, int key, int min, int max, int n){
	if (preIdx >= n)
		return NULL;

	TreeNode *root = NULL;
	if (key > min && key < max){
		root = newNode(key);
		preIdx++;
	}
	else
		return root;

	if (preIdx < n)
		root->left = createBST(pre, preIdx, pre[preIdx], min, root->val, n);
	if (preIdx < n)
		root->right = createBST(pre, preIdx, pre[preIdx], root->val, max, n);
	return root;
}
// Function - 2
TreeNode *newNode(int key){
	TreeNode *temp = new TreeNode();
	temp->val = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


// Code 2 - With Complete Syntax
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct Node *constructTreeUtil(vector<int> pre, int &preIdx, int key, 
								int min, int max, int n){
	if (preIdx >= n)
		return NULL;

	struct Node *root = NULL;

	if (key > min && key < max){
		root = newNode(key);
		preIdx++;
	}
	else
		return root;
	if (preIdx < n)
		root->left = constructTreeUtil(pre, preIdx, pre[preIdx], min, key, n);
	if (preIdx < n)
		root->right = constructTreeUtil(pre, preIdx, pre[preIdx], key, max, n);

	return root;
}

struct Node *constructTree(vector<int> pre){
	int n = pre.size();
	int preIdx = 0;
	return constructTreeUtil(pre, preIdx, pre[0], INT_MIN, INT_MAX, n);
}

void printInorder(struct Node *root){
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

int main(){
	int n;
	cin >> n;
	vector<int> pre(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];

	struct Node *root = NULL;
	root = constructTree(pre);

	printInorder(root);

	return 0;
}
