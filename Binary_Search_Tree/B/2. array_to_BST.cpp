#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* newNode(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Node* insert(int arr[],int l,int r){
    int mid=(l+r)/2;
    
    if(l<=r){
        struct Node *root=newNode(arr[mid]);
        root->left=insert(arr,l,mid-1);
        root->right=insert(arr,mid+1,r);
        return root;
    }
    return NULL;
}
void preorder(struct Node *root){
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    struct Node *root=NULL;
	    root=insert(arr,0,n-1);
	    
	    preorder(root);
	    cout<<endl;
	}
	return 0;
}
