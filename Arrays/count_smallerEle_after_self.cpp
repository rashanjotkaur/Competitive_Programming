// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Method 1 - O(n*n) ..... TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector <int> fre(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j])
                    fre[i]++;
            }
        }
        return fre;
    }
};


// Method 2 - Using lower_bound and distance...
// Submission Detail
// 63 / 65 test cases passed.
// Status: Time Limit Exceeded
// https://leetcode.com/submissions/detail/687041602/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        long long int n=nums.size();
        vector <int> fre(n);
        multiset <long long int> set;
        for(long long int i=n-1;i>=0;i--){
            set.insert(nums[i]);
            auto it=set.lower_bound(nums[i]);
            fre[i]=distance(set.begin(),it);
        }
        return fre;
    }
};


// Method 3 - Using BST
// Use a simple Binary Search Tree with 2 extra fields: 
// 1) to hold the elements on the left side of a node 
// 2) to store the frequency of element. 
// In this approach, we traverse the input array from the ending to the beginning and add the elements into the BST. 
// While inserting the elements to the BST, we can compute the number of elements which are lesser elements simply by computing the 
// sum of frequency of the element and the number of elements to the left side of current node, if we are moving to right side of the current node. 
// Once we place an element in it’s correct position, we can return it’s this sum value.
    
int insertNode(Node * &root,int value,int frequency){
        if(root==NULL){
            root=new Node(value,0);
            return frequency;
        }
        if(root->val<value)
            return root->fre + insertNode(root->right,value,frequency+1);
        else{
            root->fre++;
            return insertNode(root->left,value,frequency);
        }
}
vector<int> countSmaller(vector<int>& nums) {
        long long int n=nums.size();
        vector <int> fre(n,0);
        Node *root=NULL;
        for(long long int i=n-1;i>=0;i--)
            fre[i]=insertNode(root,nums[i],0);
        
        return fre;    
}
