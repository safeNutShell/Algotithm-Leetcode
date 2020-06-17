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
const int n = 10000001;
int Tree[n];
int sum[n];

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
	int N;
	cin >> N;
	for (int i = 1; i < n; i++) {
		Tree[i] = -1;
		sum[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a = findRoot(a);
		b = findRoot(b);
		if (a != b) {
			Tree[a] = b;
      //记录了每个集合中元素的个数
			sum[b] += sum[a];
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (Tree[i] == -1) {
			ans = sum[i] > ans ? sum[i] : ans;
		}
	}
	cout << ans << endl;
	return 0;
}
