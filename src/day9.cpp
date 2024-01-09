// Problem: https://leetcode.com/problems/leaf-similar-trees/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    void travel(TreeNode* root, vector<int>& leafs) {
        if (!root->left && !root->right) {
            leafs.push_back(root->val);
        }
        if (root->left) travel(root->left, leafs);
        if (root->right) travel(root->right, leafs);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        travel(root1, leafs1);
        travel(root2, leafs2);

        return leafs1 == leafs2;
    }
};
