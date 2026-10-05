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
    vector<int> rightSideView(TreeNode* root) {
        // we need to do a lvel order traveral, but then we always take the last entry

        vector<int> solution;
        if (!root) return solution;

        queue<TreeNode*> pendingTraversal;
        pendingTraversal.push(root);

        while(!pendingTraversal.empty()) {
            size_t currentLevelSize = pendingTraversal.size();

            // we want to pick the last one in teh queue. but we also need to queue all of the children
            for (size_t index = 0; index < currentLevelSize; index++) {
                TreeNode* currentNode = pendingTraversal.front();
                pendingTraversal.pop();

                if (index == currentLevelSize - 1) {
                    solution.emplace_back(currentNode->val);
                }

                if(currentNode->left) pendingTraversal.push(currentNode->left);
                if(currentNode->right) pendingTraversal.push(currentNode->right);
            }

        }
        return solution;
        
        
    }
};
