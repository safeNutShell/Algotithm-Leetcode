/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/

int findTargetSumWays(vector<int>& nums, int S) {
	int n = nums.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}
	if (abs(S) > abs(sum)) return 0;
	int** dp = new int* [nums.size()];
	for (int i = 0; i < nums.size(); i++) dp[i] = new int[2 * sum + 1];
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < 2 * sum + 1; j++)
			dp[i][j] = 0;
	if (nums[0] == 0)
		dp[0][sum] = 2;
	else {
		dp[0][sum + nums[0]] = 1;
		dp[0][sum - nums[0]] = 1;
	}
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 0; j < 2 * sum + 1; j++) {
			int l = (j - nums[i]) >= 0 ? j - nums[i] : 0;
			int r = (j + nums[i]) < (2 * sum + 1) ? j + nums[i] : 2 * sum;
			dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
		}
	}
	return dp[n - 1][sum + S];
}
