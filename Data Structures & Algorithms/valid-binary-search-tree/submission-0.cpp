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
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }

    bool validate(TreeNode* root, int left, int right){

        if(root == NULL){
            return true;
        }

        if(!(left < root->val && right > root->val)){
            return false;
        }

        return validate(root->left, left, root->val) && validate(root->right, root->val,right );
    }

   
};
