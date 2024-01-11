// Problem: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int dif = 0;

    void travel(TreeNode* node, int minVal, int maxVal) {
        if (!node) return;

        dif = max({dif, abs(node->val - minVal), abs(node->val - maxVal)});
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        travel(node->left, minVal, maxVal);
        travel(node->right, minVal, maxVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        int minVal = root->val, maxVal = minVal;
        travel(root, minVal, maxVal);

        return dif;
    }
};
