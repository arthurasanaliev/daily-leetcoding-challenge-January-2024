// Problem: https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        for (auto& match : matches) {
            if (!losses.count(match[0])) {
                losses[match[0]] = 0;
            }
            if (!losses.count(match[1])) {
                losses[match[1]] = 0;
            }
            losses[match[1]]++;
        }

        vector<vector<int>> ans(2);
        for (auto& [player, num] : losses) {
            if (num <= 1) ans[num].push_back(player);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};
