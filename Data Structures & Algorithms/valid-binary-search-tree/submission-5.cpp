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
        // in order traversal and then while we traverse we make sure that the current > before
        if (!root) return true;
        return isValidBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool isValidBST(TreeNode* root, const int min, const int max) {
        if(!root) return true;

        if (root->val <= min || root->val >= max) {
            return false;
        } else {
            const bool isLeftTraversalValid = isValidBST(root->left, min, root->val);
            const bool isRightTraversalValid = isValidBST(root->right, root->val, max);
            return isLeftTraversalValid && isRightTraversalValid;
        }
    }


};
