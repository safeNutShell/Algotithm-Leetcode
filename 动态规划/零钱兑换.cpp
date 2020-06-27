/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 *-1。
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
完全背包问题
*/

int coinChange(vector<int>& coins, int amount) {
    int num = coins.size();
    int** dp = new int* [num + 1];
    for (int i = 0; i < num + 1; i++) dp[i] = new int[amount + 1];
    for (int i = 0; i < num + 1; i++) dp[i][0] = 0;
    for (int i = 0; i < amount + 1; i++) dp[0][i] = INT_MAX;
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i - 1] >= 0) {
                if (dp[i][j - coins[i - 1]] != INT_MAX) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[num][amount] < INT_MAX)
        return dp[num][amount];
    else
        return -1;
}
