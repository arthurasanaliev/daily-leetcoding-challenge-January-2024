// Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        int ans = 0;
        for (auto& [num, cnt] : mp) {
            if (cnt == 1) return -1;
            ans += (cnt + 2) / 3; // ceiling
        }

        return ans;
    }
};
