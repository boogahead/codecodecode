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
    string answer="";
    void recursion(TreeNode* root){
      if(root==nullptr){
        return;
        }
        //answer+="(";
      answer+=to_string(root->val);
      if(root->left==nullptr&&root->right==nullptr)return;
      answer+="(";
      recursion(root->left);
      answer+=")";
      if(root->right!=nullptr){
        answer+="(";
      recursion(root->right);
      answer+=")";
      }
    }
    string tree2str(TreeNode* root) {
      recursion(root);
      return answer;
    }
};
