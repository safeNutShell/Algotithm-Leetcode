/*
在计算机界中，我们总是追求用有限的资源获取最大的收益。
现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
二维01背包问题
*/

int findMaxForm(vector<string>& strs, int m, int n) {
	int num = strs.size();
	int m_count, n_count;
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < num; i++) {
		m_count = 0;
		n_count = 0;
		for (int j = 0; j < strs[i].size(); j++) {
			if (strs[i][j] == '0') m_count++;
			else n_count++;
		}
		for (int j = m; j >= m_count; j--) {
			for (int k = n; k >= n_count; k--) {
				dp[j][k] = max(dp[j][k], dp[j - m_count][k - n_count] + 1);
			}
		}
	}
	return dp[m][n];
}
