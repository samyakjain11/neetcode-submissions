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
    int goodNodes(TreeNode* root) {
        // dfs, we construct the current path, and we make sure that its in increasing order
        return dfs(root, root->val);

        
    }
private:
    int dfs(const TreeNode* root, const int maxValSeen) {
        if (!root) return 0;
        const int good = root->val >= maxValSeen ? 1 : 0;
        const int newMaxValSeen = max(maxValSeen, root->val);
        
        return good + dfs(root->left, newMaxValSeen) + dfs(root->right, newMaxValSeen);

    }
};
