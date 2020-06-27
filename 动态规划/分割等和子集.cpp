/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
动态规划，01背包问题
*/

bool canPartition(vector<int>& nums) {
	int sum = 0;
	int num = nums.size();
	for (int i = 0; i < num; i++) {
		sum += nums[i];
	}
	if (sum % 2 == 1) return false;
	int capacity = sum / 2;
	bool** dp = new bool*[num + 1];
	for (int i = 0; i < num + 1; i++) dp[i] = new bool[capacity + 1];
	for (int i = 0; i < capacity + 1; i++) dp[0][i] = false;
	for (int i = 0; i < num + 1; i++) dp[i][0] = true;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= capacity; j++) {
			if (j - nums[i - 1] >= 0) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[num][capacity];
}
