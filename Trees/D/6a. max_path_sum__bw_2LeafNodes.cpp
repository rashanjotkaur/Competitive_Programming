// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/#

class Solution {
public:
    int maxPath(Node* root,int &maxSum){
        if(root==NULL) 
    	    return 0;
    	    
    	if(root->left==NULL && root->right==NULL) 
    	    return root->data;
    
    	int l = maxPath(root->left, maxSum);
    	int r = maxPath(root->right, maxSum);
    
    	if(root->left && root->right){
    		maxSum = max(maxSum, l+r+root->data);
    		return max(l, r) + root->data;
    	}
            
    	return root->left?l+root->data:r+root->data;
    }
    int maxPathSum(Node* root){
        if(root==NULL)
            return 0;
        int maxSum=INT_MIN;
        int sum=maxPath(root,maxSum);
        //--- for this test case --- 
        // sum: 4
        // maxSum: INT_MIN
    	//	  7				
    	//	 / \			
    	// Null -3	
        if(root->left && root->right)
            return maxSum;
        return max(maxSum,sum);
    }
};
