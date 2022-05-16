// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    void bottom(struct Node *root,int hd,int l,map <int,pair<int,int>> &mp){
        if(root==NULL)
            return;

        if(mp.count(hd)==0)
            mp[hd]=make_pair(root->data,l);

        else if(mp[hd].second<=l)
            mp[hd]=make_pair(root->data,l);

        bottom(root->left,hd-1,l+1,mp);
        bottom(root->right,hd+1,l+1,mp);
    }
    vector <int> bottomView(Node *root) {
        vector <int> res;
        if(root==NULL)
            return res;
        map <int,pair<int,int>> mp;
        bottom(root,0,0,mp);
        for(auto it=mp.begin();it!=mp.end();it++){
            int hd=it->first;
            pair<int,int> pi=it->second;
            res.push_back(pi.first);
        }
        return res;
    }
};