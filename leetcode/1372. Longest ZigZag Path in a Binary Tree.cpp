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
    int answer=0;
    void dfs(TreeNode* root,int count,bool left)
    {
        if(root==nullptr)return;
        answer=max(answer,count);
        if(left)
        {
            dfs(root->right,count+1,false);
            dfs(root->left,1,true);
        }
        if(!left)
        {
            dfs(root->left,count+1,true);
            dfs(root->right,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left,1,true);
        dfs(root->right,1,false);
        return answer;
    }
};
