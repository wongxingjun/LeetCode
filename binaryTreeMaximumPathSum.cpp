/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return res;
    }
    
    int maxPath(TreeNode* node){
        if(node==NULL)
            return 0;
        int l=max(0,maxPath(node->left));
        int r=max(0,maxPath(node->right));
        res=max(res,l+r+node->val);
        return max(l,r)+node->val;
    }
};
