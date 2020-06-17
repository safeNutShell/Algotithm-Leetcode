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
int Tree[1000];

int findRoot(int a) {
	if (Tree[a] == -1)
		return a;
	else {
		int tmp = findRoot(Tree[a]);
		Tree[a] = tmp;
		return tmp;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	//初始时认为所有节点自称一个集合
	for (int i = 1; i <= n; i++) Tree[i] = -1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a = findRoot(a);
		b = findRoot(b);
		if (a != b) {
			//若输入的两个点不在一个集合里，将第一个点merge进第二个集合
			//实际上就是赋值a的根为b的根
			Tree[a] = b;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (Tree[i] == -1) ans++;
	}
	cout << ans - 1 << endl;
	return 0;
}
