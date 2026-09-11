/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int pathsum(TreeNode * root,int &ans){
    if(root==nullptr){
        return 0;
    }
    int left=max(0,pathsum(root->left,ans));
    int right=max(0,pathsum(root->right,ans));
    int curr=left+right+root->val;
    ans=max(ans,curr);
    return root->val+max(left,right);
}

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
    pathsum(root,ans);
    return ans;
    }
};