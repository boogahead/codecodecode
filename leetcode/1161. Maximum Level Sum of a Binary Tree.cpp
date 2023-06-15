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
    unordered_map<int,long> table; //level sum
    void calc(TreeNode* root,int level)
    {
        if(root==NULL)return;
        table[level]+=root->val;
        calc(root->left,level+1);
        calc(root->right,level+1);
        return;   
    }
    int maxLevelSum(TreeNode* root) {
        table.insert({1,root->val});
        calc(root->left,2);
        calc(root->right,2);
        int minlevel=1;
        for(auto i:table)
        {
            //cout<<i.first<<" "<<i.second<<"\n";
            if(table[minlevel]<i.second)minlevel=i.first;
        }
        return minlevel;
    }
};
