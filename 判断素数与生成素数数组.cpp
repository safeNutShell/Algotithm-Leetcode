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

//判断是否为素数
bool judge(int a) {
	//0,1不是素数
	if (a <= 1) return false;
	int bound = (int)sqrt(a) + 1;
	//判断2到根a（向上取整）是否整除a
	for (int i = 2; i < bound; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	int a = 7;
	if (judge(a)) cout << "YES" << endl;
	bool prime[100] = { false };
	for (int i = 2; i < 100; i++) {
		prime[i] = judge(i);
	}
	for (int i = 0; i < 100; i++) {
		if (prime[i])
			cout << i << ' ';
	}
	return 0;
}
