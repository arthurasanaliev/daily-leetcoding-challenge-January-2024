// Problem: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cur = 0, ans = 0;
        
        for (auto& floor : bank) {
            int cnt = 0;
            for (auto& cell : floor) {
                if (cell == '1') cnt++;
            }
            if (cnt == 0) continue;
            ans += cur * cnt;
            cur = cnt;
        }

        return ans;
    }
};
