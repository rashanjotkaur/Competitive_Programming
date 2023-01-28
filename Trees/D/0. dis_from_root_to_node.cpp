// Find distance from root to given node in a binary tree
// https://www.geeksforgeeks.org/find-distance-root-given-node-binary-tree/

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int key){
	Node *temp = new Node();
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void findDistanceFun(Node *root, int level, int &maxLevel, bool &exist, int x){
    if(root==NULL)
        return ;
    if(root->data==x){
        maxLevel=level;
        exist=true;
        return ;
    }
    findDistanceFun(root->left,level+1,maxLevel,exist,x);
    findDistanceFun(root->right,level+1,maxLevel,exist,x);
}
int findDistance(Node *root, int x){
	int maxLevel=0;
	bool exist=false;
	findDistanceFun(root,0,maxLevel,exist,x);
	return exist?maxLevel:-1;
}

int main(){
	Node *root = newNode(5);
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->left->right = newNode(25);
	root->left->right->right = newNode(45);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

	cout<<findDistance(root, 45)<<endl;
	cout<<findDistance(root, 5)<<endl;
	cout<<findDistance(root, 35)<<endl;
	cout<<findDistance(root, 40)<<endl;
	return 0;
}

