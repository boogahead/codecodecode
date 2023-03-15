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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qq;
        qq.push(root);
        bool answer=false;
        while(!qq.empty())
        {
            TreeNode* tmp=qq.front();qq.pop();
            if(tmp==NULL)answer=true;
            else
            {
                if(answer)return false;
                qq.push(tmp->left);
                qq.push(tmp->right);
            }
        }
        return true;
    }
};
