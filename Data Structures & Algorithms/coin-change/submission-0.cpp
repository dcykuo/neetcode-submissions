class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Step 1: Initialize DP array
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // Step 2: compute minimum coins
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        // Step 3: return result
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
