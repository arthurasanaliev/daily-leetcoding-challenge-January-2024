// Problem: https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n / 2; i++) {
            cnt1 += vowels.count(s[i]);
            cnt2 += vowels.count(s[i + n / 2]);
        }

        return cnt1 == cnt2;
    }
};
