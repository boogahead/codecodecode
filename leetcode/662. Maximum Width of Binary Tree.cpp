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
    typedef pair<TreeNode*,long long>info;
    int answer=0;
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<info>qq;
        qq.push({root,1});
        while(!qq.empty())
        {
            int depthsize=qq.size();
            int startpos=qq.front().second;
            int endpos=qq.back().second;
            answer=max(answer,endpos-startpos+1);
            TreeNode* tmp;int pos;
            for(int i=0;i<depthsize;i++)
            {
                tie(tmp,pos)=qq.front();qq.pop();
                long long offset=pos-startpos;
                if(tmp->left)qq.push({tmp->left,2*offset});
                if(tmp->right)qq.push({tmp->right,2*offset+1});
            }
        }
        return answer;
    }
};
/*
since the values get extremely big when graph is laid out as a tree going down in depth straight down without any width-based expansion,
gotta use long long
while loop acts as a way to find the first and last position of the node of the same depth
for loop inside the while loop acts as a way to find all the locations of the nodes of the same depth
*/
