class Solution {
public:
    static const int MOD = 1e9 + 7;

    int memo[205][201][201];

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            return (g1 == g2 && g1 != 0);
        }

        if (memo[idx][g1][g2] != -1)
            return memo[idx][g1][g2];

        long long ans = 0;

        // Skip
        ans += solve(idx + 1, g1, g2, nums);

        // Put into first subsequence
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans += solve(idx + 1, ng1, g2, nums);

        // Put into second subsequence
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans += solve(idx + 1, g1, ng2, nums);

        return memo[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};