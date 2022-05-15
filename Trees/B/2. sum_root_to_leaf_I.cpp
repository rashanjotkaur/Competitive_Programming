// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1/#

class Solution{
public:
    void heightCal(struct Node *root,int sum,int height,int &maxSum,int &maxHeight){
        if(root==NULL){
            if(height>=maxHeight){
                maxSum=sum;
                maxHeight=height;
            }
            return ;
        }
        heightCal(root->left,sum+root->data,height+1,maxSum,maxHeight);
        heightCal(root->right,sum+root->data,height+1,maxSum,maxHeight);
    }
    int sumOfLongRootToLeafPath(Node *root){
        if(root==NULL)
            return 0;
        int maxSum=INT_MIN,maxHeight=INT_MIN;
        heightCal(root,0,0,maxSum,maxHeight);
        return maxSum;
    }
};
