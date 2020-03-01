判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
空的位置用'.'表示

bool isValidSudoku(vector<vector<char>>& board) {
	vector <vector<bool>> row(9, vector<bool>(9,false));
	vector <vector<bool>> col(9, vector<bool>(9,false));
	vector <vector<bool>> square(9, vector<bool>(9,false));
	int n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '0' - 1;
			if (!row[i][num]) {
				row[i][num] = true;
			}
			else {
				return false;
			}
			if (!col[j][num]) {
				col[j][num] = true;
			}
			else {
				return false;
			}
			int square_no = 3 * (i / 3) + (j / 3);
			if (!square[square_no][num]) {
				square[square_no][num] = true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

/*
一开时也是想到为9*3次检查创建27个set用于存储和判断，但是这样写起来很复杂而且空间复杂度较高。
仔细考虑本题，要判断是否重复的对象是数字，而且仅可出现一次，因此用bool型的数组比较好。
在空间声明方面，动态的数组应用嵌套的vector；在vector变量名后面用两个参数进行初始化，第一个参数声明了这个vector的大小，第二个参数是初始化值。
之后对board一次遍历同时加以比较即可。
*/
