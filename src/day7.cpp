// Problem: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        long long ans = 0;
        vector<unordered_map<long long, long long>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long dif = 1ll * nums[i] - nums[j];
                dp[i][dif] += dp[j][dif] + 1;
                ans += dp[j][dif] + 1;
            }
        }

        ans -= (n * (n - 1) / 2);

        return (int)ans;
    }
};
