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
    void dfs(TreeNode* root,int value)
    {
        if(root->left==NULL&root->right==NULL)
        {
            answer+=value*10+root->val;
            //cout<<answer<<"\n";
            return;
        }
        if(root->left!=NULL){
        dfs(root->left,value*10+root->val);}
        if(root->right!=NULL){
        dfs(root->right,value*10+root->val);}
    }
    int sumNumbers(TreeNode* root) {
        //dfs(root->left,root->val);
        //dfs(root->right,root->val);
        if(root->left==NULL&root->right==NULL)
        {
            //cout<<"HI\n";
            answer+=root->val;return answer;
        }
        if(root->left!=NULL){
        dfs(root->left,root->val);}
        if(root->right!=NULL){
        dfs(root->right,root->val);}
        return answer;
    }
};
