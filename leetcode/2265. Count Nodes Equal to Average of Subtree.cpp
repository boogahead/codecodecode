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
    typedef pair<int,int>info;//sum,count
    info recursion(TreeNode* root){
        if(root==nullptr)return {0,0};
        info left=recursion(root->left);
        info right=recursion(root->right);
        if((left.first+right.first+root->val)/(left.second+right.second+1)==root->val)answer++;
        return {left.first+right.first+root->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        recursion(root);
        return answer;
    }
};
