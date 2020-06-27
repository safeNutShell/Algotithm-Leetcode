/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/

int findTargetSumWays(vector<int>& nums, int S) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (S > sum || S < -sum) return 0;
	//注意还有负的半边
	int column = 2 * sum + 1;
	int row = nums.size();
	int** dp = new int*[row];
	for (int i = 0; i < row; i++) dp[i] = new int[column];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			dp[i][j] = 0;
	//初始化
	if (nums[0] == 0)
		dp[0][sum] = 2;
	else {
		dp[0][sum + nums[0]] = 1;
		dp[0][sum - nums[0]] = 1;
	}
	for (int i = 1; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (j - nums[i] >= 0)
				dp[i][j] += dp[i - 1][j - nums[i]];
			if (j + nums[i] <= column)
				dp[i][j] += dp[i - 1][j + nums[i]];
			
		}
	}
	return dp[row - 1][sum + S];
}
