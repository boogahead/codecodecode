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
    vector<int>lefty;
    vector<int>righty;
    void right(TreeNode*root)
    {
        if(root==NULL)
        {
            righty.push_back(-1);return;
        }
        righty.push_back(root->val);
        right(root->right);
        right(root->left);
    }
    void left(TreeNode*root)
    {
        if(root==NULL)
        {
            lefty.push_back(-1);return;
        }
        lefty.push_back(root->val);
        left(root->left);
        left(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL)return true;
        if(root->left==NULL||root->right==NULL)return false;
        lefty.push_back(root->val);
        righty.push_back(root->val);
        left(root->left);
        right(root->right);
        return lefty==righty;
    }
};
