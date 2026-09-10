class Solution {
   
public:
    pair<int,int> dfs(TreeNode* root,int &ans){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> l=dfs(root->left,ans);
        pair<int,int> r=dfs(root->right,ans);
        int tsum=root->val+l.first+r.first;
        int count=l.second+r.second+1;
        if(root->val==(tsum/count)){
            ans++;
        }
        return {tsum,count};


    }
    int averageOfSubtree(TreeNode* root) {
       int ans=0;
       pair<int,int> x= dfs(root,ans);
       return ans;
    }
};