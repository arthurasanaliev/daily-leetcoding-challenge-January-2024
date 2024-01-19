// Problem: https://leetcode.com/problems/minimum-falling-path-sum/

// Time Complexity: O(n * n)
// Space Complexity: O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cur = grid[i - 1][j];
                if (j > 0) cur = min(cur, grid[i - 1][j - 1]);
                if (j < n - 1) cur = min(cur, grid[i - 1][j + 1]);
                grid[i][j] += cur;
            }
        }   

        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, grid[n - 1][j]);
        }

        return ans;
    }
};
