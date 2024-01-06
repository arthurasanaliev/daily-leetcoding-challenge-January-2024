// Problem: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int lastTrue(int lo, int hi, function<bool(int)> f) {
        lo--;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();

        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int ind = lastTrue(0, n - 1, [&](int k) {
                return jobs[k][0] <= jobs[i - 1][1];
            });
            dp[i] = max(dp[i - 1], (ind == -1 ? 0 : dp[ind + 1]) + jobs[i - 1][2]);
        }

        return dp[n];
    }
};
