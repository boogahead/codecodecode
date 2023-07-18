/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 use dfs
 mid = if current node IS one of p or q
 left = if one of the nodes on the left hand side equals p or q
 right = if one of the nodes on the right hand side equals p or q
 */
class Solution {
public:
    TreeNode* ans;
    bool checker(TreeNode*cur,TreeNode* p,TreeNode* q)
    {
        if(cur==NULL)return false;
        int left=checker(cur->left,p,q);
        int right=checker(cur->right,p,q);
        int mid=(cur==p||cur==q);
        if(mid+left+right>=2)ans=cur;
        // ^ if the value is more than 2, this means that p and q have been found
        return mid+left+right>0;
        // ^ tell at least one of the node has been found 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        checker(root,p,q);
        return ans;
    }
};
