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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> solution;
        if (!root) return solution;

        std::queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while(!pendingNodes.empty()) {
            const size_t levelSize = pendingNodes.size();
            vector<int> currentLevel;
            currentLevel.reserve(levelSize);

            for(size_t index = 0; index < levelSize; index++) {
                TreeNode* currentNode = pendingNodes.front();
                pendingNodes.pop();

                currentLevel.emplace_back(currentNode->val);
                if (currentNode->left) pendingNodes.push(currentNode->left);
                if (currentNode->right) pendingNodes.push(currentNode->right);
            }

            solution.emplace_back(std::move(currentLevel));
        }

        return solution;
    }
};
