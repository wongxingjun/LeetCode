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
    int countNodes(TreeNode* root) {
        int res=0;
        if(root==NULL)
            return res;
        int lh=0,rh=0;
        TreeNode *left=root,*right=root;
        while(left!=NULL){
            lh++;
            left=left->left;
        }
        while(right!=NULL){
            rh++;
            right=right->right;
        }
        if(lh==rh)
            return pow(2,lh)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
