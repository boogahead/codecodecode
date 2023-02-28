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
    vector<TreeNode*> answer;
    string dfs(TreeNode* root,unordered_map<string,int> &table)
    {
        if(!root)return "";
        string left=dfs(root->left,table);
        string right=dfs(root->right,table);
        string tmp=to_string(root->val)+","+left+","+right;
        if(table[tmp]==1){answer.push_back(root);}
        table[tmp]++;
        return tmp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> table;
        dfs(root,table);
        return answer;
    }
};
