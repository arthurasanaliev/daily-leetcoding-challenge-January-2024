// Problem: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26), cnt2(26);
        for (auto& x : s) cnt1[x - 'a']++;
        for (auto& x : t) cnt2[x - 'a']++;

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += abs(cnt1[i] - cnt2[i]);
        }

        return cnt / 2;
    }
};
