/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/

int uniquePaths(int m, int n) {
int** res = new int*[n];
for (int i = 0; i < n; i++) {
  res[i] = new int[m];
}
for (int i = 0; i < m; i++)
  res[0][i] = 1;
for (int i = 0; i < n; i++)
  res[i][0] = 1;
for (int i = 1; i < n; i++) {
  for (int j = 1; j < m; j++) {
    res[i][j] = res[i - 1][j] + res[i][j - 1];
  }
}

return res[n - 1][m - 1];
  }

/*
典型的动态规划问题，分析如何到达当前块，然后把问题分解下去
为了到达当前块，可以从左、上块出发
值得记忆的是多维数组的初始化和顺序
*/
