#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

int main() {
	int G[5][5] = {
	{0,1,999,999,55},
	{999,0,1,999,999},
	{999,999,0,1,999},
	{999,999,999,0,1},
	{1,999,999,999,0}
	};
	int D[5][5];
	int path[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
      //初始化为原图即可，不连接的点其边用无限大表示（注意后面加法会溢出），D[i][i]设置为0
			D[i][j] = G[i][j];
			path[i][j] = -1;//用于记录路径，-1表示没有路径
		}
	}
  //核心是三层循环，每层循环都遍历数组一遍，判断加入点k后是否让路径变短
  //是否变短的判断很简单，见if判断
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;//表示从i到j的对端路径上前一个点是k
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << path[i][j] << "\t";
		}
		cout << endl;
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int>p;
	p.push_back(v2);
  //为了得到最短路径，遍历path，直到-1，此遍历路径得到途经点的逆序
	while (path[v1][v2] != -1) {
		p.push_back(path[v1][v2]);
		v2 = path[v1][v2];
	}
	p.push_back(v1);
	for (int i = p.size()-1; i >= 0 ; i--) {
		cout << p[i];
		if (i != 0)
			cout << "->";
	}
	return 0;
}
