// Problem: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int dfs(TreeNode* node, int cnt_odd, vector<int>& cnt) {
        // base case
        if (!node) return 0;

        cnt[node->val]++;
        int change = (cnt[node->val] & 1) ? 1 : -1;
        cnt_odd += change;

        int res;
        if (!node->left && !node->right) {
            res = (cnt_odd <= 1);
        } else {
            res = dfs(node->left, cnt_odd, cnt) + dfs(node->right, cnt_odd, cnt);
        }

        cnt[node->val]--;
        cnt_odd -= change;

        return res;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> cnt(10);
        return dfs(root, 0, cnt);
    }
};
