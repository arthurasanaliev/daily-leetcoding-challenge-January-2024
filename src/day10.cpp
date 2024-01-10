// Problem: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void constructGraph(TreeNode* root) {
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            constructGraph(root->left);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            constructGraph(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        unordered_set<int> used;
        queue<int> q;

        q.push(start);
        used.insert(start);
        
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();

                for (auto& x : adj[cur]) {
                    if (used.count(x)) continue;
                    q.push(x);
                    used.insert(x);
                }
            }
            if (!q.empty()) ans++;
        }

        return ans;
    }
};

