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
    unordered_map<int,int> table;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int& postidx)
    {
        if(start>end)return NULL;
        int inidx=table[postorder[postidx]];
        TreeNode*root=new TreeNode(inorder[inidx]);
        postidx--;
        root->right=solve(inorder,postorder,inidx+1,end,postidx);
        root->left=solve(inorder,postorder,start,inidx-1,postidx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            table[inorder[i]]=i;
        }
        int postidx=postorder.size()-1;
        return solve(inorder,postorder,0,postorder.size()-1,postidx);

    }
};
